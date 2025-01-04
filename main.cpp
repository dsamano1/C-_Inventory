#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <windows.h>
#include "clothes.h"
#include "writeCSV.h"
#include "readCSV.h"

void Menu(std::vector<Clothes> cVector){
    int input;

    std::cout << "\n++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "+    Welcome to Marlen's Clost!    +" <<std::endl;
    std::cout << "++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "+    Here are our current options: " << "+" <<std::endl;
    std::cout << "++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "+    Please enter an Integer       +"<< std::endl;
    std::cout << "++++++++++++++++++++++++++++++++++++\n" << std::endl;
    std::cout << "(1) View Entire Wardrobe/Inventory " << std::endl;
    std::cout << "(2) View Tops Only" << std::endl;
    std::cout << "(3) View Bottoms Only" << std::endl;
    std::cout << "(4) Add a new clothing item" << std::endl;

    std::cin >> input; 

    switch (input){
        case 1:
        {
            std::cout << "You Chose View Entire Wardrobe/Inventory: " << std::endl;
            for (Clothes item : cVector){ // prints each row
                item.display();
            }
            break;
        }   
        case 2:
        {
            std::cout << "You Chose View View Tops Only:  " << std::endl;
            for (int i = 0; i < cVector.size(); i++){
                if (cVector[i].getClothing() == "Top")
                    cVector[i].display();
            }
            break;
        }
        case 3: 
        {
            std::cout << "You Chose View Bottom Only: " << std::endl;
            for (int i = 0; i < cVector.size(); i++){
                if (cVector[i].getClothing() == "Bottom")
                    cVector[i].display();
            }
            break;
        }
        case 4:
        {
            //initializes the data to add at the end to the vector
            int nID = cVector.size() + 1;
            std::string nBrand;
            std::string nColor;
            std::string nClothing;
            std::string nAoc;
            std::string nStatus;

            std::cout << "You Chose To Add A New Clothing Item: " << std::endl;
            std::cout << "Please enter a single or double word such as \"Skirt\" or \"High Rise\"\n" << std::endl;

            std::cout << "Please Enter Brand: " << std::endl;
            std::getline(std::cin >> std::ws, nBrand);

            std::cout << "Please Enter Color: " << std::endl;
            std::getline(std::cin >> std::ws, nColor);

            std::cout << "Please Enter Clothing (Top, Bottom, Shoes etc): " << std::endl;
            std::getline(std::cin >> std::ws, nClothing);

            std::cout << "Please Enter Article of Clothing(Jeans, High Rise, etc): " << std::endl;
            std::getline(std::cin >> std::ws, nAoc);

            std::cout << "Please Enter Status (Clean or Dirty): " << std::endl;
            std::getline(std::cin >> std::ws, nStatus);

            Clothes new_item(nID, nBrand, nColor, nClothing, nAoc, nStatus);
            cVector.push_back(new_item);
            std::cout << "You added: " << std::endl;
            new_item.display();

            bool pass = WtoFile("inventory.csv", new_item);
            if (pass == true){
                Sleep(500);
                Menu(cVector);
            }
            break;
        }
        default:
        {
            std::cout << "WRONG INPUT TRY AGAIN \n";
            Sleep(500);
            Menu(cVector);
        }
    }
}
int main(){
    std::vector<Clothes> cVector; // creates vector of class "Clothes"

    int current = RtoCSV("inventory.csv", cVector); // reads Inventory 

    Menu(cVector);
    return 0;
}



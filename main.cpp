#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <windows.h>
#include "clothes.h"

void readCSV(const std::string& filename, std::vector<Clothes>& cVector){
    std::ifstream file(filename);

    if (!file.is_open()){
        std::cerr << "Failed opening file" << filename << std::endl;
    }

    std::string line;

    std::getline(file, line); //skips first row 

    while(std::getline(file, line)){
        std::stringstream ss(line);

        std::string id;
        std::string brand;
        std::string color;
        std::string clothing;
        std::string aoc;
        std::string status;

        // reads each column based on the comma
        std::getline(ss, id, ',');
        std::getline(ss, brand, ',');
        std::getline(ss, color, ',');
        std::getline(ss, clothing, ',');
        std::getline(ss, aoc, ',');
        std::getline(ss, status, ',');

        int int_id = std::stoi(id); // Converts ID to an integer

        Clothes item(int_id, brand, color, clothing, aoc, status); // creates the class from the data
        cVector.push_back(item);
    }

    file.close();
}

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
            for (Clothes item : cVector){ // prints each row
                item.display();
            }
            break;
        case 2:

            break;
        case 3: 

            break;
        case 4:
            
            break;
        default:
            std::cout << "WRONG INPUT TRY AGAIN \n";
            Sleep(1000);
            Menu(cVector);
    }
}
int main(){
    std::vector<Clothes> cVector; // creates vector of class "Clothes"

    readCSV("inventory.csv", cVector); // reads Inventory 

    Menu(cVector);
    return 0;
}



#ifndef ITEM_H
#define ITEM_H
#include <string>

class Clothes {
    private:
        int id;             // id number for keeping track
        std::string brand;; // brand of clothes
        std::string color;  // color of clothes
        std::string clothing; // examples: top, bottom,shoes, hat, etc
        std::string aoc;    // Article of clothing (AOC)
        std::string status; // whether it is clean or dirty 

    public:
    // Constructor
        Clothes(int c_id, std::string c_brand, std::string c_color, std::string c_clothing,std::string c_aoc, std::string c_status);
        
    // Getters
        int getId();
        std::string getBrand();
        std::string getColor();
        std::string getClothing();
        std::string getAoc();
        std::string getStatus();
    // Setters
        int setId(int c_id);
        std::string setBrand(std::string c_brand);
        std::string setColor(std::string c_color);
        std::string setClothing(std::string c_clothing);
        std::string setAoc(std::string c_aoc);
        std::string setStatus(std::string c_status);
    // Displays Cloth
        void display();
};
#endif
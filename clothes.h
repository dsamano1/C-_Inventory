#ifndef CLOTHES_H
#define CLOTHES_H
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
        void setId(int c_id);
        void setBrand(std::string c_brand);
        void setColor(std::string c_color);
        void setClothing(std::string c_clothing);
        void setAoc(std::string c_aoc);
        void setStatus(std::string c_status);
    // Displays Cloth
        void display();
    // To add string to CSV file
        std::string add();
};
#endif
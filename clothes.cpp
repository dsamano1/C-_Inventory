#include <iostream>
#include <string>
#include <iomanip>
#include "clothes.h"

//typedef std::string string;

// Constructor
    Clothes::Clothes(int c_id, std::string c_brand, std::string c_color, std::string c_clothing,std::string c_aoc, std::string c_status){
        id = c_id;
        brand = c_brand;
        color = c_color;
        clothing = c_clothing;
        aoc = c_aoc;
        status = c_status;
    }
    /////////////////////////////////////////////////////
// Getters
    int Clothes::getId(){
        return id;
    }
    std::string Clothes::getBrand(){
        return brand;
    }
    std::string Clothes::getColor(){
        return color;
    }
    std::string Clothes::getClothing(){
        return clothing;
    }
    std::string Clothes::getAoc(){
        return aoc;
    }
    std::string Clothes::getStatus(){
        return status;
    }
    ////////////////////////////////////////////////////////////////
// Setters
    void Clothes::setId(int c_id){
        id = c_id;
    }
    void Clothes::setBrand(std::string c_brand){
        brand = c_brand;
    }
    void Clothes::setColor(std::string c_color){
        color = c_color;
    }
    void Clothes::setClothing(std::string c_clothing){
        clothing = c_clothing;
    }
    void Clothes::setAoc(std::string c_aoc){
        aoc = c_aoc;
    }
    void Clothes::setStatus(std::string c_status){
        status = c_status;
    }
    ///////////////////////////////////////////////////////////////
// Displays Cloth
    void Clothes::display(){
        std::cout << std::setw(15) << id << std::setw(15) << brand << std::setw(15) << color << std::setw(15) << clothing << std::setw(15) << aoc << std::setw(15) << status << std::endl;
    }
// creates to a single string used to write to CSV file
    std::string Clothes::add(){
        return std::to_string(id) + "," + brand + "," + color + "," + clothing + "," + aoc + "," + status;
    }
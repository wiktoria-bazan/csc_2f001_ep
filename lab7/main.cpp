#include<iostream>
#include<string>
#include "treemap.h"

int main(int arg, char* argv[]){
    treemap_t<std::string, double> map;

    map["Tyrion"] = 2;
    map["Jaime"] = 15;
    map["Cersei"] = 63;
    map["Tywin"] = 75;
    map["Kevan"] = 48;
    map["Lancel"] = 70;
    map["Alton"] = 54;
    map["Martyn"] = 32;
    map["Willem"] = 6;

    //std::cout << map.at("Kevan") << std::endl;

    //map.display();
    
    for(auto& [key, value]: map) {
        std::cout << key << " => " << value << std::endl;
    }

    account_t a = 42;
    a.note = "best client ever";
    std::cout << a << std::endl;
}
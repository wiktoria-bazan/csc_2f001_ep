#include<iostream>
#include<string>
#include "treemap.h"

int main(int arg, char* argv[]){
    treemap_t<std::string, double> map;
    std::string name;

    name = "Tyrion";
    //std::cout<<map.lookup(&map.root, nullptr, &name, true)->key<<"\n";
    map.lookup(&map.root, nullptr, &name, true);
    name = "Jaime";
    //std::cout<<map.lookup(&map.root, nullptr, &name, true)->key<<"\n";
    map.lookup(&map.root, nullptr, &name, true);
    name = "Cersei";
    map.lookup(&map.root, nullptr, &name, true);

    map.set_at("Tyrion", 2);
    map.set_at("Jaime", 15);
    map.set_at("Cersei", 63);
    map.set_at("Tywin", 75);
    map.set_at("Kevan", 48);
    map.set_at("Lancel", 70);
    map.set_at("Alton", 54);
    map.set_at("Martyn", 32);
    map.set_at("Willem", 6);

    //std::cout << map.at("Kevan") << std::endl;

    map.display();
        
}
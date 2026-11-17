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
}
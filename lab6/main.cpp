#include<iostream>
#include<string>
#include "treemap.h"

int main(int arg, char* argv[]){
    treemap_t<std::string, double>::pair_t pair;
    pair.key = "Tyrion";
    pair.value = 2.0;
    std::cout << pair.key << ": " << pair.value << "€" << std::endl;
}
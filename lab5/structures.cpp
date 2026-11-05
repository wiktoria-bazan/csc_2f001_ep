#include<iostream>
#include "structures.h"


node_t* node_t::eval(){
    return this;
}
void error(std::string str) __attribute__((noreturn));

void error(std::string str) {
  std::cout << "Error: " << str << std::endl;
  exit(1);
}

node_t* node_t::apply(list_t* list){
    error("Node is an integer or a list");
}

std::string node_t::to_string(){
    return "???";
}

list_t* node_t::as_list(){
    error("Node is not necessary a list");
}

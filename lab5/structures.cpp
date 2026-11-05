#include<iostream>
#include "structures.h"


//NODE
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

//INTEGER

integer_t::integer_t(uintptr_t value):
value{value}{};

std::string integer_t::to_string(){
    return std::to_string(value);
}

//LIST

list_t::list_t():
elements{nullptr}, nb_elements{0}, capacity{0}{};


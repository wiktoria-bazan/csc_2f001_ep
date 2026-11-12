#include<iostream>
#include "structures.h"

//ERROR
void error(std::string str) __attribute__((noreturn));

void error(std::string str) {
  std::cout << "Error: " << str << std::endl;
  exit(1);
}

//NODE
node_t* node_t::eval(){
    return this;
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

list_t* list_t::as_list(){ 
    return this;
}

size_t list_t::size(){
    return nb_elements;
}

node_t* list_t::at(size_t i){
    if(i >= nb_elements) error("Index is bigger than the number of elements");
    return *(elements + i);
}

void list_t::set_at(size_t i, node_t* value){
    if(i >= nb_elements) error("Index is bigger than the number of elements");
    *(elements + i) = value;
}

void list_t::append(node_t* value){
    if(capacity == 0){
        capacity = 1;
        elements = new node_t*[capacity];
    }
    else if(nb_elements == capacity){
        capacity <<= 1;
        node_t** new_nodes = new node_t*[capacity];
        for(int i = 0;i<nb_elements;i++)
            new_nodes[i] = elements[i];

        elements = new_nodes;
    }
     
    *(elements + nb_elements) = value;  
    nb_elements += 1;
}

std::string list_t::to_string(){
    std::string rep = "(";

    for(int i = 0;i<nb_elements;i++){
        rep += (*(elements + i))->to_string();
        
        if(i < nb_elements  - 1)
            rep += " ";
    }

    rep += ")";
    return rep;
}

node_t* list_t::eval(){
    node_t* first = (*elements)->eval();
    node_t* calc = first->apply(as_list());
    return calc;
}

//KEYWORD

keyword_t::keyword_t(std::string id):id{id}{};
std::string keyword_t::to_string(){
    return "<" + id + ">";
}

//ADD
add_t::add_t():keyword_t("+"){};

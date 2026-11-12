#include<iostream>
#include "structures.h"

//ERROR
void error(std::string str) __attribute__((noreturn));

void error(std::string str) {
  std::cout << "Error: " << str << std::endl;
  exit(1);
}

//NODE
node_t* node_t::eval(frame_t* frame){
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

uintptr_t node_t::int_value(){
    error("Node is not an integer");
}

bool node_t::is(std::string id){
    return false;
}

//INTEGER

integer_t::integer_t(uintptr_t value):
value{value}{};

std::string integer_t::to_string(){
    return std::to_string(value);
}

uintptr_t integer_t::int_value(){
    return value;
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

node_t* list_t::eval(frame_t* frame){
    node_t* first = (*elements)->eval(frame);
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

node_t* add_t::apply(list_t* list, frame_t* frame){
    uintptr_t result = 0;
    for(int i = 1; i < list->nb_elements;i++)
        result += list->at(i)->eval(frame)->int_value();
    return new integer_t{result};
}

//SYMBOL 

symbol_t::symbol_t(std::string id):id{id}{}

bool symbol_t::is(std::string id){
    return this->id == id;
}

std::string symbol_t::to_string(){
    return id;
}

//CALL FRAMES

void frame_t::set(node_t* sym, node_t* value){
    for(int i=0;i<nb_elements;i++){
        if(sym->is(at(i)->as_list()->at(0)->to_string())) { 
            at(i)->as_list()->set_at(1, value);
            return;
        }
    }
    //we create a new symbol
    list_t* ns = new list_t;
    ns->append(sym);
    ns->append(value);
    append(ns);
}

node_t* frame_t::get(node_t* sym){
    for(int i=0;i<nb_elements;i++){
        if(sym->is(at(i)->as_list()->at(0)->to_string())) { 
            return at(i)->as_list()->at(1);
        }
    }
    error("Value does not exist");
}
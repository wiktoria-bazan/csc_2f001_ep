#include "structures.h"
#include<iostream>

int main(int argv, char* argc[]){
    node_t* add = new add_t;
    symbol_t* a = new symbol_t { "a" };
    frame_t* frame = new frame_t;
    set_t* set = new set_t;

    list_t* ast = new list_t;

    //(set! a (+ 1 2)) example
    ast->append(set);
    ast->append(a);
    ast->append(new list_t);
    ast->at(2)->as_list()->append(add);
    ast->at(2)->as_list()->append(new integer_t { 1 });
    ast->at(2)->as_list()->append(new integer_t { 2 });

    std::cout << ast->to_string() << " => ";

    ast->eval(frame);

    for(int i=0;i<frame->nb_elements;i++){
        std::cout<<(frame->as_list() + i)->to_string()<<std::endl;
    }
    return 0;
}

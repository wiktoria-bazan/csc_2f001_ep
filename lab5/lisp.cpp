#include "structures.h"
#include<iostream>

int main(int argv, char* argc[]){
    node_t* ast = new integer_t { 3 };
    std::cout << ast->to_string() << " => " << ast->eval()->to_string() << std::endl;
    return 0;
}

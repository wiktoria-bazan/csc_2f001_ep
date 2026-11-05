#ifndef STRUCTURES
#define STRUCTURES

#include<string>

struct list_t;

struct node_t{
virtual node_t* eval();
virtual node_t* apply(list_t* list);
virtual std::string to_string();
virtual list_t* as_list();
};

struct integer_t:node_t{
    uintptr_t value;
    
    integer_t(uintptr_t value);
    std::string to_string();
};

struct list_t{
    node_t** elements;
    size_t nb_elements;
    size_t capacity;

    list_t();
};



#endif
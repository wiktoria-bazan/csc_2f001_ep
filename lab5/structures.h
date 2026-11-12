#ifndef STRUCTURES
#define STRUCTURES

#include<string>

struct list_t;

struct node_t{
virtual node_t* eval();
virtual node_t* apply(list_t* list);
virtual std::string to_string();
virtual list_t* as_list();
virtual uintptr_t int_value();
virtual bool is(std::string id);
};

struct integer_t:node_t{
    uintptr_t value;
    
    integer_t(uintptr_t value);
    std::string to_string();
    uintptr_t int_value();
};

struct list_t:node_t{
    node_t** elements;
    size_t nb_elements;
    size_t capacity;

    list_t();

    list_t* as_list();
    size_t size();
    node_t* at(size_t i);
    void set_at(size_t i, node_t* value);
    void append(node_t* value); 
    std::string to_string();
    
    node_t* eval();
};

struct keyword_t:node_t{
    std::string id;

    keyword_t(std::string id);
    std:: string to_string();
};

struct add_t:keyword_t{
    add_t();

    node_t* apply(list_t* list);
};

struct symbol_t:node_t{
    std::string id;
    symbol_t(std::string id);
    bool is(std::string id);
    std::string to_string();
};

#endif
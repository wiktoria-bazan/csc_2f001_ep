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

#endif
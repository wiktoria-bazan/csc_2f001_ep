#include<string>
#include<iostream>

struct list_t{};

struct node_t{
virtual node_t* eval();
virtual node_t* apply(list_t* list);
virtual std::string to_string();
virtual list_t* as_list();
};

struct keyword_t{};
struct integer_t{};

void error(std::string str) __attribute__((noreturn));

void error(std::string str) {
  std::cout << "Error: " << str << std::endl;
  exit(1);
}
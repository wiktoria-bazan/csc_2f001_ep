#include "location.h"

location_t::location_t(std::string name, double latitude, double longitude)
: name{name}, latitude{latitude}, longitude{longitude}{}


void location_t::set_neighbors(location_t* list[]){
    neighbors = *list;
    nb_neighbors = 0;
    while(*list != nullptr){
        nb_neighbors += 1;
        list += 1;
    }
}
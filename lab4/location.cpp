#include "location.h"
#include<numbers>
#include<cmath>

location_t::location_t(std::string name, double latitude, double longitude)
: name{name}, latitude{latitude}, longitude{longitude}{}

location_t::~location_t(){
    delete[] neighbors;
}

void location_t::set_neighbors(location_t* list[]){
    neighbors = list;
    nb_neighbors = 0;
    while(*list != nullptr){
        nb_neighbors += 1;
        list += 1;
    }
}

double location_t::distance_to(location_t* to){
    double R = 6378;
    return R * (std::numbers::pi/2 - std::asin(std::sin(to->latitude) * std::sin(latitude) + std::cos(to->longitude - longitude) * std::cos(to->latitude) * std::cos(latitude)));
}   

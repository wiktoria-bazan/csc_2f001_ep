#ifndef _LOCATION_
#define _LOCATION_


#include<string>

struct location_t{
    std::string name;
    double latitude;
    double longitude;
    location_t** neighbors; //int* - pointer pointing at int, analogously location_t** - pointer (array) at (of) location_t* 
    size_t nb_neighbors;

    location_t(std::string name, double latitude, double longitude);
    void set_neighbors(location_t* list[]);
};


#endif

#ifndef _LOCATION_
#define _LOCATION_


#include<string>

struct location_t{
    std::string name;
    double latitude;
    double longitude;
    location_t* neighbors;
    int size_t;

    location_t(std::string name, double latitude, double longitude);
};


#endif

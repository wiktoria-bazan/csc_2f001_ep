#include<string>
#include<iostream>

struct monster_t{
    std::string name;
    int health;
};

std::ostream& operator << (std::ostream& os, const monster_t& m){
    os<<"Name: "<<m.name<<" "<<"\nHealth points: "<<m.health;
    return os;
}

int main(int arg, char* argv[]){
    monster_t m{"Pikachu", 0};
    std::cout<<m<<"\n";
    return 0;
}
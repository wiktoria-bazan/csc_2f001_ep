#include<string>
#include<iostream>
#include<vector>

struct monster_t{
    std::string name;
    int health;
};

std::ostream& operator << (std::ostream& os, const monster_t& m){
    os<<"Name: "<<m.name<<", Health points: "<<m.health<<"\n";
    return os;
}

int main(int arg, char* argv[]){

    std::vector<monster_t> army;
    for(int i=0;i<10;i++){
        monster_t m{"Pikachu-" + std::to_string(i), 0};
        army.push_back(m);
    }
    //first method
    std::cout<<"FIRST\n";
    for(auto &var: army){
        std::cout<<var;
    }

    //second method
    std::cout<<"SECOND\n";
    for(auto &[name, health]: army){
        std::cout<<"Name: "<<name<<", Health points: "<<health<<"\n";
    }

    //third 
    std::cout<<"THIRD\n";
    for(auto i = army.begin(); i != army.end(); ++i){
        monster_t var = *i;
        std::cout<<var;
    }
    return 0;
}
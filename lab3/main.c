#include<stdlib.h>
#include<stdio.h>
#include "monster.h"
#include "army.h"

int main(int argc, char* argv[]){
    struct monster *m[10];
    struct army *a = create_army();

    for(int i=0;i<10;i++){
        char name[NAME_SIZE];
        snprintf(name, NAME_SIZE, "Pikachu-%i", i);
        m[i] = create_monster(name, 0);
        add_monster_to_army(a, m[i]);
    }
    display_army(a);
    delete_army(a);
    return 0;
}
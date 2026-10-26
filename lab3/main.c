#include<stdlib.h>
#include<stdio.h>
#include "monster.h"

int main(int argc, char* argv[]){
    struct monster *m[10];
    printf("haha");
    for(int i=0;i<10;i++){
        char name[NAME_SIZE];
        snprintf(name, NAME_SIZE, "Pikachu-%i", i);
        m[i] = create_monster(name, 0);
    }
    for(int i=0;i<10;i++)
        display_monster(m[i]);
    for(int i=0;i<10;i++)
        delete_monster(m[i]);
    return 0;
}
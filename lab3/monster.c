#include <string.h>
#include <stdlib.h>
#include<stdio.h>

#include "monster.h"
#include "macro.h"


struct monster* create_monster(char* name, int health){
    struct monster* m = malloc(sizeof(*m));
    for(int i=0; name[i] != 0; i++){
        m->name[i] = name[i];
        if(name[i + 1] == 0) m->name[i + 1] = 0;
    }
    m->health = health;
    return m;
}

void display_monster(struct monster* m){
    printf("Name: ");
    for(int i=0; m->name[i] != 0; i++){
        printf("%c", m->name[i]);
    }
    printf("\nHealth points: %i\n", m->health);
}

void delete_monster(struct monster *m){
    free(m);
}

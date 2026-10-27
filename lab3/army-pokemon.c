#include "army.h"
#include<stdio.h>
#include <stdlib.h>

struct army {
  struct monster** monsters; // a pointer to an array, where each element of the array is a pointer to a monster
  int top;                   // where you have the last monster in the array
  int capacity;              // the capacity of the array
};

struct army* create_army(){
    struct army *a = malloc(sizeof(*a));
    a->monsters = NULL;
    a->top = 0;
    a->capacity = 0;
    return a;
}

void add_monster_to_army(struct army* a, struct monster *m){
    if(a->capacity == 0){
        a->monsters = malloc(sizeof(*a->monsters));
        a->capacity = 1;
    }
    else if(a->top == a->capacity){
        a->capacity *= 2;
        a->monsters = realloc(a->monsters, a->capacity*sizeof(*a->monsters));
    }

    a->monsters[a->top] = m;
    a->top += 1;
}


void display_army(struct army* a){
    for(int i=0; i<a->top; i++)
        display_monster(a->monsters[i]);
}

void delete_army(struct army* a){
    free(a->monsters);
    free(a);
}
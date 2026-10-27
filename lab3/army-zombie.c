#include "army.h"
#include<stdio.h>
#include <stdlib.h>

struct node{
    struct monster* monster;
    struct node* next;
};

struct army {
  struct node* first;
  int stars;
};

struct army* create_army(){
    struct army *a = malloc(sizeof(*a));
    a->first = NULL;
    a->stars = 0;
    return a;
}

void add_monster_to_army(struct army* a, struct monster *m){
    if(a->first == NULL){
         a->first = malloc(sizeof(*a->first));
        a->first->monster = m;
        a->first->next = NULL;
    }else{
        struct node* last = a->first;
        while(last->next != NULL)
            last = last->next;

        last->next = malloc(sizeof(*last));
        last->next->monster = m;
        last->next->next = NULL;
    }
}


void display_army(struct army* a){
    printf("This is a %i stars army\n", a->stars);
    struct node* last = a->first;
    while(last != NULL){
        display_monster(last->monster);
        last = last->next;
    }
}

void delete_army(struct army* a){
    struct node* last = a->first;
    while(last != NULL){
        struct node* help = last->next;
        free(last);
        last = help;
    }
    free(a);
}
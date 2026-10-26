#ifndef _ARMY_
#define _ARMY_

#include "monster.h"

struct army {
  struct monster** monsters; // a pointer to an array, where each element of the array is a pointer to a monster
  int top;                   // where you have the last monster in the array
  int capacity;              // the capacity of the array
};

extern struct army* create_army();
extern void add_monster_to_army(struct army* a, struct monster *m);
extern void display_army(struct army* a);
extern void delete_army(struct army* a);

#endif
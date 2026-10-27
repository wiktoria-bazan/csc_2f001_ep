#ifndef _ARMY_
#define _ARMY_

#include "monster.h"

struct army;

extern struct army* create_army();
extern void add_monster_to_army(struct army* a, struct monster *m);
extern void display_army(struct army* a);
extern void delete_army(struct army* a);

#endif
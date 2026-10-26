#ifndef _MONSTER_
#define _MONSTER_


struct monster{
    char name[256];
    int health;
};

extern struct monster* create_monster(char* name, int health);
extern void display_monster(struct monster* m);
extern void delete_monster(struct monster *m);

#endif
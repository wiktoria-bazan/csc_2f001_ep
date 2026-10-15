#include<stdlib.h>
#include<stdio.h>
#include "monster.h"

int main(int argc, char* argv[]){
    struct monster *m = create_monster("Pikachu", 0);
    display_monster(m);
    delete_monster(m);
    return 0;
}
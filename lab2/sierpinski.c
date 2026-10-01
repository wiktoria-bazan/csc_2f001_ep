#include<stdio.h>
#include<stdlib.h>

int sort_get_index(float *tab, int top, float val){
    for(int i = 0; i<top; i++){
        if(tab[i] > val)
            return i;
    }
    return top;
}


void sort_insert_at(float *tab, int i, int top, float val){
    for(int j = top; j > i; j--)
        tab[j] = tab[j - 1];
    
    tab[i] = val;
    return;
}

void sort_insert(float *tab, int top, float val){
    int index = sort_get_index(tab, top, val);
    sort_insert_at(tab, index, top, val);
}

 int nb_columns(){
    return 32;
 }

int nb_lines(){
    return 16;
}

int main(int argc, char* argv[]){
    printf("nb_columns is %d, nb_lines is %d", nb_columns(), nb_lines());
    return 0;
}
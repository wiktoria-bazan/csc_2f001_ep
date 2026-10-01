#include<stdio.h>
#include<stdlib.h>

int sort_get_index(float *tab, int top, float val){
    for(int i = 0; i<top; i++){
        if(tab[i] > val)
            return i;
    }
    return top;
}

int main(int argc, char* argv[]){
    float tab[] = {1, 3, 5, 7, 0};
    printf("Insert 0 at %d, 3.5 at %d, 10 at %d\n", sort_get_index(tab, 4, 0),  sort_get_index(tab, 4, 3.5),  sort_get_index(tab, 4, 10));
    for(int i = 0; i<5; i++)
        printf("%f ", tab[i]);
    return 0;
}
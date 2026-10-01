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
    for(int i = 0; i<5; i++)
        printf("%f ", tab[i]);
    return 0;
}
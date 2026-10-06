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
    return;
}

int nb_columns(){
    return 32;
 }

int nb_lines(){
    return 16;
}

void grid_init(char* grid, char pixel){
    for(int i =0; i<nb_columns()*nb_lines(); i++)
        grid[i] = pixel;
    return;
}

void grid_display(char* grid){
    for(int i = 0; i < nb_lines(); i++){
        for(int j = 0; j < nb_columns(); j++){
            printf("%c", grid[i * nb_columns() + j]);
        }
        printf("\n");
    }
    return;
}

void plot_point(char* grid, int x, int y, char pixel){
    if(y < 0 || y >= nb_columns())
        exit(EXIT_FAILURE);
    if(x < 0 || x >= nb_lines())
        exit(EXIT_FAILURE);
    grid[(nb_lines() - y - 1)*nb_columns() + x] = pixel;
    return;
}

void plot_vline(char* grid, int x, float fy0, float fy1, char pixel){
    int y0 = (int)(fy0 + 0.5);
    if(fy0 == y0 - 0.5) y0--;
    int y1 = (int)(fy1 + 0.5);
    for(int y = y0; y <= y1; y++)
        plot_point(grid, x, y, pixel);
    return;
}


struct point{
    float x, y;
};

void plot_poly_sweep(char* grid, struct point* p, int np, int x, char pixel){
    printf("sweep %i: ", x);
    for(int i = 0; i<np; i++){
        int j = (np + i - 1) % np;
        if((p[j].x <= x && x <= p[i].x) || (p[i].x <= x && x <= p[j].x)){
            float y = p[i].y + (x - p[i].x) * (p[j].y - p[i].y) / (p[j].x - p[i].x);
            printf("%f ", y);
        }
    }
    printf("\n");
}

void plot_poly(char* grid, struct point* p, int np, char pixel){
    for(int i = 0; i<nb_columns();i++)
        plot_poly_sweep(grid, p, np, i, pixel);
}

int main(int argc, char* argv[]){
    char grid[nb_lines()*nb_columns()];
    grid_init(grid, ' ');
    struct point a[] = {{ 2, 13 }, { 10, 13 }, { 30, 7 }, { 10, 1 }, { 2, 1 }, { 18, 7 }};
    plot_poly(grid, a, 6, 'X');
    grid_display(grid);
    return 0;
}
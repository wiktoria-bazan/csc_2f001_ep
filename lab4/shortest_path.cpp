#include "shortest_path.h"
#include<iostream>
#include<string>


shortest_path_t::shortest_path_t(location_t* from,  location_t* to)
: head{nullptr}, base{nullptr}, from{from}, to{to}{}

shortest_path_t::~shortest_path_t(){
    while(head != nullptr){
        node_t* help = head->next;
        delete head;
        head = help;
    } 
}

void shortest_path_t::compute(){
    head = new node_t{nullptr,from,nullptr,0,from->distance_to(to),false};
    while(true){
        node_t* node = head;
        while(node != nullptr && node->visited) node = node->next;
        if(node == nullptr) return;

        base = node;
        while(node != nullptr){
            if(!node->visited && (base->total > node->total))
                base = node;
            node = node->next;
        } 
        if(base->location == to) return;
        base->visited = true;
        for(int i=0;i<base->location->nb_neighbors;i++){
            location_t* curr = base->location->neighbors[i];
            double from_origin = base->from_origin + base->location->distance_to(curr);
            double total = from_origin + curr->distance_to(to);

            node = head;
            while(node->next != nullptr && (node->location != curr)) node = node->next;
            if(node->location == curr){
                if(node->from_origin > from_origin){
                    node->from_origin = from_origin;
                    node->from = base;
                    node->total = total;
                    node->visited = false;
                }
            }else{
                node->next = new node_t{nullptr, curr, base, from_origin, total, false};
            }
        }
        
    }
}

void shortest_path_t::display(){
    base = head;
    while(base->location != to){
            base=base->next;
            if(base == nullptr) {
                std::cout<<"unable to find a path from "<<from->name<<" to "<<to->name<<"\n";
                return;
            }
    }

    int count = 0;
    node_t* node = base;
    while(node != head){
        node = node->from;
        count += 1;
    }

    node_t** arr = new node_t*[count + 1];
    int i = 0;
    while(base != head){
        arr[i] = base;
        base = base->from;
        i += 1;
    }
    arr[count] = head;

    std::cout<<"path from "<<from->name<<" to "<<to->name<<"\n";
    for(int i = count; i>=0;i--) 
        std::cout<<"* "<<arr[i]->location->name<<" at "<<arr[i]->from_origin<<"km from "<<from->name<<"\n";

    delete[] arr;
    }
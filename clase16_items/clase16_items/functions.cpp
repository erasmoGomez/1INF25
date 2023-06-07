/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "functions.hpp"
#include "item.hpp"
#include "backpack.hpp"

void load_items(Item * items, int n_items,const char * filename){
    ifstream arch(filename, ios::in);
    while(1){
        Item i;
        arch>>i;
        if(arch.eof()) break;
        items[n_items] = i;
        n_items++;
    }
    
}

int is_valid(Backpack * backpacks, Backpack &b, int n){
    if (n == 0) return -1;
    int i=0;
    for(i=0;i<n;i++){
        if(backpacks[i].GetID() == b.GetID())
            return i;
    }
    return -1;
}

void update_backpacks(Backpack * backpacks, int pos, int n_backpacks, Backpack &b, Item * items, int n_items){
    int encontrado;
    for(int i=0;i<n_items;i++)
        if(items->GetID()==b.GetItem(0).GetID())
            encontrado = i;
    backpacks[n_backpacks].SetItem(items[encontrado],pos);
}

void load_backpacks(Backpack * backpacks, Item * items, int n_items, const char* filename){
    ifstream arch(filename, ios::in);
    int n_items_bag[20]={};
    int n_backpacks= 0;
    int pos = 0;
    while(1){
        Backpack b;
        arch>>b;
        if(arch.eof()) break;
        pos = is_valid(backpacks,b, n_backpacks);
        cout<<pos<<endl;
        if(pos==-1)
            backpacks[n_backpacks] = b;
        else
            update_backpacks(backpacks, pos, n_backpacks, b, items, n_items);
    }
}
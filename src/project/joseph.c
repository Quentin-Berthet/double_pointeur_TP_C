//
// Created by quentin.berthet1 on 29.04.19.
//

//dependances

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "circ_liste.h"


int compare(void* el_1, void* el_2) {
    return (*(int*)el_1 == *(int*)el_2);
}

void data_free(void* data){
    free(data);
}

void print(void* content) {
    printf("%d\n", *(int*)content);
}


int main (int argc, char *argv[]) {
    if (argc == 3) {
        int n = atoi(argv[1]);
        int k = atoi(argv[2]);
        Element* lst = list_create();   //cree une liste vide
        if (n > 0 && k > 0) {   //si k et n  positif
            for (int i = 1; i <= n; i++) {
                int* data = calloc(1, sizeof(int));
                *data = i;
                lst = list_insert_after(lst, data); //on insert les valeurdans l'ordre dans la liste
            }
            while (n > 0) {
                for (int i = 0; i < k; i++) {   //deplace pointeur sur 3 eme element
                    lst = list_move(lst);
                }
                Element* target = list_remove(lst, lst->content, compare);  //on le sors
                printf("%d\n", *(int*)target->content); //on l'imprime
                n--;
            }
            list_free(lst, data_free);  //on supprime la liste
        }
    }
    return 0;
}
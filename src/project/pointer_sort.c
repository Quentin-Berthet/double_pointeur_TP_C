//
// Created by quentin on 5/4/19.
//

#include "pointer_sort.h"
#include <stdlib.h>
#include <stdio.h>
# include <stdbool.h>

int* alloc_pointer(int* tab, int size){
    int* ptr_before = calloc(1, sizeof(int*)*size);
    for(int i=0;i<size;i++){
        ptr_before[i]=tab[i];  //fait correspondre chaque case du tableau de pointeur a celle correpondante dans le tableau de valeur
    }
    return ptr_before;
}

void swap(int* ptr_1, int* ptr_2){  //swap 2 element
    int tmp_ptr = *ptr_1;
    *ptr_1 = *ptr_2;
    *ptr_2 = tmp_ptr;
}

void tri_bulle(int* ptr_before,int size){
    for(int i=size;i >= 2; i--){    //effectue le tri jsuqua quil reste au moins 2 cases
        for(int y=0;y<i-1;y++){
            if (ptr_before[y]>ptr_before[y+1]){ //si element precedent plus grand que le suivant
                swap(&ptr_before[y],&ptr_before[y+1]);  //on les swap
            }
        }
    }
}

int main(int argc, char *argv[]){

    int size = argc - 1;
    if (size != 0) {    //si la taille n'est pas nule
        int tab[size];  //cree tableau de la taille definit par utlilisateur
        for (int i = 0; i < size; i++) {
            tab[i] = atoi(argv[i + 1]); //rempli tableau avec valeur donner par utilisateur
        }

        int *ptr_array = alloc_pointer(tab, size);
        tri_bulle(ptr_array, size); //effectue tri a bulle
        for (int i = 0; i < size; i++) {
            printf("\n %d ", ptr_array[i]);  //imprime chaque element du tableau de pointeur
        }
        return 0;
    } else {
        printf(" Il n'y a pas assez d'argument! \n");
        exit(1);
    }
}
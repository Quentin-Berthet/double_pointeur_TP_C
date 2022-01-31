//
// Created by quentin on 5/4/19.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "matrice.h"


int main(int argc, char *argv[]){
    if (argc == 4){
        //recupere matrice 1 et 2 et creer matrice de sortie
        m_double* first_matrix = get_file(argv[2]);
        m_double* second_matrix = get_file(argv[3]);
        m_double* result_matrix = NULL;
        //cas ou on fait l'addition ou la multiplication
        bool operator=0;//0 = addition et 1 = multiplication
        if (strcmp(argv[1],"mult")==0){
            operator = 1;
        }
        else if (strcmp(argv[1],"add")==0){
            operator = 0;
        }
        else{
            printf("operation non reconnu\n");
            exit(1);
        }
        if (operator){
            result_matrix = matrix_mult(first_matrix,second_matrix);
        }
        else{
            result_matrix = matrix_add(first_matrix,second_matrix);
        }
        if (result_matrix != NULL){    //si matrice pas vide alors on l'imprime
            printf(" %d %d\n",result_matrix->row,result_matrix->col);
            print_matrix(result_matrix);
        }
        //libère toute les matrice
        matrix_free(first_matrix);
        matrix_free(second_matrix);
        matrix_free(result_matrix);
    }
    //cas ou on fait une transposee
    if (argc == 3){
        m_double* m = get_file(argv[2]);
        printf(" %d %d\n",m->col,m->row);
        print_matrix(matrix_transpose(m));
        matrix_free(m);
    }

}
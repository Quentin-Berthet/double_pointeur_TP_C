//
// Created by quentin.berthet1 on 29.04.19.
//

#include "matrice.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>





m_double* matrix_alloc(unsigned int row, unsigned int col) {
    if(row > 0 && col > 0) {
        m_double *new_matrix;
        new_matrix = calloc(1, sizeof(m_double));   //cree nouvelle matrice
        new_matrix->content = calloc(1, row * sizeof(double *));    //aloue la place pour contenu des lignes
        for (unsigned int i = 0; i < row; i++) {
            new_matrix->content[i] = calloc(1, col * sizeof(double));   //aloue la place pour contenu des colones
        }
        new_matrix->row = row;
        new_matrix->col = col;
        return new_matrix;
    } return NULL;

}

m_double* matrix_add(m_double* m1, m_double* m2){
    m_double* add;
    if(m1 == NULL || m2 == NULL)
        return NULL;
    if(m1->row != m2->row || m1->col != m2->col)    //verifie que matrice meme dimention
        return NULL;
    add = matrix_alloc(m1->row, m2->col);   //cree matrice add
    for(unsigned i = 0; i < (m1->row); i++){  //parcourt lignes
        for(unsigned j = 0; j < (m1->col); j++)   //parcourt colones
            add->content[i][j] = m1->content[i][j] + m2->content[i][j]; //chaque case de matrice add remplie avec somme element correspondant de m1 et m2
    }
    return add;
}

m_double* matrix_mult(m_double* m1, m_double* m2){
    m_double* product;
    if(m1 == NULL || m2 == NULL)
        return NULL;
    if(m1->col != m2->row)  //s'assure que les deux matrice sont multipliable
        return NULL;
    double tmp = 0.0;
    product = matrix_alloc(m1->row, m2->col);
    for(unsigned i = 0; i < m1->row; i++){
        for(unsigned j = 0; j < m2->col; j++) {
            for (unsigned k = 0; k< m1->col; k++){
                tmp += m1->content[i][k] * m2->content[k][j]; //multiplication element ligne m1 et element colone m2
            }
            product->content[i][j]= tmp; //tmp devient contenu de la matrice resultante
            tmp =0;
        }
    }
    return product;
}


void matrix_free(m_double* m) {
    free(m->content[0]);
    free(m->content);
}

m_double* matrix_transpose(m_double* m){
    if (m == NULL){
        return NULL;
    }
    m_double* transpose;
    transpose = matrix_alloc(m->col,m->row);
    for (unsigned int  i=0; i < (transpose->row);i++){  //parcourt les lignes
        for (unsigned int  j=0; j < (transpose->col);j++){  //parcourt les colones
            transpose->content[i][j] = m->content[j][i];    //interverti lignes et colones
        }
    }
    return transpose;
}


m_double* get_file(char* filename){
    FILE *fp = fopen(filename,"r+");
    if (NULL == fp) {
        fprintf(stderr,"%s, file not found\n",filename);
        exit(1);
    }
    int li = 0, co = 0;
    fscanf(fp,"%d",&li);
    fscanf(fp,"%d",&co);
    m_double* mat = matrix_alloc(li,co);
    for (unsigned int i=0;i<mat->row;i++)
        for (unsigned int j=0;j<mat->col;j++)
            fscanf(fp,"%lf ",&(mat->content[i][j]));
    fclose(fp);
    return mat;

}

void print_matrix(m_double* matrix){
    for (unsigned int i=0; i < (matrix->row);i++){
        for (unsigned int j=0; j < (matrix->col);j++){
            printf(" %g ",matrix->content[i][j]);   //parcourt element de chaque case de d'une matrice et l'imprime
        }
        printf("\n");
    }
}

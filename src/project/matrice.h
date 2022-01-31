//
// Created by quentin.berthet1 on 29.04.19.
//

#ifndef DOUBLE_POINTEUR_MATRICE_H
#define DOUBLE_POINTEUR_MATRICE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef struct m_double {
    unsigned int row, col;
    double** content;
} m_double;

m_double* matrix_alloc(unsigned int row, unsigned int col);
m_double* matrix_transpose(m_double* m);
m_double* matrix_add(m_double* m1, m_double* m2);
m_double* matrix_mult(m_double* m1, m_double* m2);
void matrix_free(m_double* m);
m_double* get_file(char* filename);
void print_matrix(m_double* matrix);
#endif //DOUBLE_POINTEUR_MATRICE_H

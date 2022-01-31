//
// Created by quentin.berthet1 on 29.04.19.
//

#ifndef DOUBLE_POINTEUR_CIRC_LISTE_H
#define DOUBLE_POINTEUR_CIRC_LISTE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Element {
    void* content;
    struct Element* next;
} Element;


Element* list_create();
bool list_empty(Element* head);
unsigned int list_count(Element* head);
Element* list_move(Element* head);
Element* list_insert_after(Element* head, void* data);
void* list_insert_before(Element* head, void* data);
Element* list_search(Element* head,void* data,int (*compare)(void*, void*));
Element* list_remove(Element* head, void* data,int (*compare)(void*, void*));
void list_free(Element* head, void (*data_free)(void*));
void list_process(Element* head, void* (*action)(void*));

#endif //DOUBLE_POINTEUR_CIRC_LISTE_H

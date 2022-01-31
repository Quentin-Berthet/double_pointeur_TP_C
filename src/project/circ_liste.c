//
// Created by quentin.berthet1 on 29.04.19.
//

#include "circ_liste.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>



Element* list_create(){
    return NULL;
}

bool list_empty(Element* head){
    return (head == NULL);
}

unsigned int list_count(Element* head){
    int counter =0;
    if (!list_empty(head)){
        Element* current = head;
        do {
            current = current->next; //on parcourt tout les element de la liste
            counter++;  //incremente le comteur
        } while(current != head);   //s'arrete des que l'on retombe sur la head
    }
    return counter;
}

Element* list_move(Element* head){
    return (!list_empty(head)) ? head->next: NULL;  //si liste pas vide deplace le pointeur ver l'element suivant
}

Element* list_insert_after(Element* head, void* data) {
    Element  *new_element;
    new_element = calloc(1, sizeof(Element));   //cree un nouvel element
    if (new_element != NULL) {
        // set the new element
        new_element->content = data;    //data devient contenu du nouvel element

        if (!list_empty(head)) {    //si la liste pas vide
            new_element->next = head->next;
            head->next = new_element;   // insert element apres la head
        } else {
            new_element->next = new_element;    //si liste vide nouvel element devient premier element et boucle sur lui meme
        }
    }
    return new_element;
}

void* list_insert_before(Element* head, void* data){
    Element* new_element;
    new_element = calloc(1, sizeof(Element));
    new_element->content = data;   //data;
    Element* current = head;    //cree un pointeur sur la head
    Element* previous = NULL;   //cree un pointeur NULL
    do {
        previous->next = current->next; //
        current->next = new_element->next;
    } while (current->next != head->next);  //tant que on est par revenu sur la la tete
    return new_element;
}

Element* list_search(Element* head, void* data, int (*compare)(void*, void*)){
    if (list_empty(head)){
        return NULL;
    }
    Element* current = head;
    do {
        if (compare(current->content, data)){   //si la fonction compare match
            return current; //retourne l'element trouver
        }
        current = current->next;    //sinon on deplace pointeur vers element suivant
    } while(current != head);    //s'arrete quand on retombe sur la head
    return NULL;
}

Element* list_remove(Element* head, void* data,int (*compare)(void*, void*)){
    if (!list_empty(head)){
        Element* current = head;
        do {    //reassigne la head a l'element suivant tant que la data ne match pas
            if (compare(head->content, data)) {
                current = head;
                while (current != head->next) { //parcourt la liste tant que le pointeur ne match pas le next
                    head = head->next;
                }
                head->next = current->next; //isole l'element hors de la liste
                return current;
            }
            head = head->next;
        } while (current != head);
    }
    return NULL;
}

void list_free(Element* head, void (*data_free)(void*)){
    if (!list_empty(head)){
        Element* end = head;    // definit la fin de la liste
        head = head->next;
        Element* current = end;
        while(end != head && end->next != NULL ){ //parcourt et supprime chaque element de la liste jusqu'a la fin
            end = end->next;
            data_free(current->content);
            free(current);
            current = end;
        }
        data_free(current->content);    //supprime le dernier element
        free(current);
    }
}

void list_process(Element* head, void* (*action)(void*)){
    if(!list_empty(head)){
        Element* start = head;  //cree pointeur sur la head
        do {
            action(head->content);  //opere action sur le contenu de la head
            head = head->next;
        } while (head != start);    //on le fait jusqua que le pointeur retombe sur la head
    }
}

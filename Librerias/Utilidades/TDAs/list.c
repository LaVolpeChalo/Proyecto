#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct node node;

struct node {
    const void * data;
    node * next;
    node * prev;
};

struct list {
    node * head;
    node * current;
    node * tail;
};

typedef list list;

node * createNode(const void * data) {
    node * new = (node *)malloc(sizeof(node));
    assert(new != NULL);
    new->prev = NULL;
    new->data = data;
    new->next = NULL;
    return new;
}

list * createList() {
     list * newList = (list *) malloc (sizeof(list));
     assert(newList != NULL);
     newList->head = NULL;
	 newList->current = NULL;
	 newList->tail = NULL;
     return newList;
}

void * firstList(list * list) {
    if (list == NULL || list->head == NULL) return NULL;
    list->current = list->head;
    return (void *)list->current->data;
}

void * nextList(list * list) {
    if (list == NULL || list->head == NULL || list->current == NULL || list->current->next == NULL) return NULL;
    list->current = list->current->next;
    return (void *)list->current->data;
}

void * lastList(list * list) {
    if (list == NULL || list->head == NULL) return NULL;
    list->current = list->tail;
    return (void *)list->current->data;
}

void * prevList(list * list) {
    if (list == NULL || list->head == NULL || list->current == NULL || list->current->prev == NULL) return NULL;
    list->current = list->current->prev;
    return (void *)list->current->data;
}

void pushFront(list * list, const void * data) 
{
	node * nodo = createNode(data);
	
	if(list->tail == NULL) 
	{
		list->tail = nodo;
		list->head = nodo;
	}
	else
	{
		nodo->next = list->head;
		nodo->prev = NULL;
		list->head->prev = nodo;
		list->head = nodo;
	}
}

void pushBack(list * list, const void * data) {
    list->current = list->tail;
    if(list->current==NULL) pushFront(list,data);
    else pushCurrent(list,data);
}

void pushCurrent(list * list, const void * data) {
    assert(list != NULL && list->current !=NULL);
    node * newNode = createNode(data);

    if(list->current->next)
        newNode->next = list->current->next;
    newNode->prev = list->current;

    if(list->current->next)
        list->current->next->prev = newNode;
    list->current->next = newNode;

    if(list->current==list->tail)
        list->tail=newNode;

}

void * popFront(list * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(list * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(list * list) {
    assert(list != NULL || list->head != NULL);
    
    if (list->current == NULL) return NULL;
    
    node * aux = list->current;
    
    if (aux->next != NULL) 
        aux->next->prev = aux->prev;
    
    
    if (aux->prev != NULL) 
        aux->prev->next = aux->next;
    
    
    void * data = (void *)aux->data;
    
    if(list->current == list->tail)
        list->tail = list->current->prev;

    if(list->current == list->head)
        list->head = list->current->next;
        
    list->current = aux->prev;

    free(aux);
    
    return data;
}

void cleanList(list * list) {
    assert(list != NULL);
    
    while (list->head != NULL) {
        popFront(list);
    }
}
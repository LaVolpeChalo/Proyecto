#ifndef list_h
#define list_h

typedef struct list list;

list * createList(void);

void * firstList(list * list);

void * nextList(list * list);

void * lastList(list * list);

void * prevList(list * list);

void pushFront(list * list, const void * data);

void pushBack(list * list, const void * data);

void pushCurrent(list * list, const void * data);

void * popFront(list * list);

void * popBack(list * list);

void * popCurrent(list * list);

void cleanList(list * list);

#endif 
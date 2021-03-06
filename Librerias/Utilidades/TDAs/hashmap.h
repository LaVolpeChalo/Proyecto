#ifndef HashMap_h
#define HashMap_h

typedef struct HashMap HashMap;

HashMap * createMap(long capacity);

void insertMap(HashMap * table, char * key, void * value);

void eraseMap(HashMap * table, char * key);

void * searchMap(HashMap * table, char * key);

void * firstMap(HashMap * table);

void * nextMap(HashMap * table);

int mapsize(HashMap * map);

void enlarge(HashMap * map);

#endif
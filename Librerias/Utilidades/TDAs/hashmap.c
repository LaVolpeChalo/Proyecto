#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"

typedef struct Pair Pair;
typedef struct HashMap HashMap;

struct Pair {
     char * key;
     void * value;
};

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}

void enlarge(HashMap * map);

void insertMap(HashMap * map, char * key, void * value) {
 if(map->size>((map->capacity)*0.7)) enlarge(map);
 Pair* x=createPair(key,value);
 long pos=hash(key,map->capacity);
  while(map->buckets[pos]!=NULL){
    if(pos>=map->capacity){
      pos=0;
    }
    pos=(pos+1)%map->capacity;
  }
  map->buckets[pos]=x;
  map->buckets[pos]->key=key;
  map->buckets[pos]->value=value;
  map->size++;
}

void enlarge(HashMap * map) {
    map->capacity *= 2;

    Pair ** oldBucket = map->buckets;
    
    long oldCapacity = map->capacity/2;

    map->buckets = (Pair **)malloc(sizeof(Pair *) * map->capacity);
    memset(map->buckets, 0, map->capacity * sizeof(Pair *));
    map->size = 0;
    long i;
    
    for (i = 0; i < oldCapacity; i++) {
        if (oldBucket[i] != NULL) {
            if (oldBucket[i]->value != NULL) {
                insertMap(map, oldBucket[i]->key, oldBucket[i]->value);
            } else {
                free(oldBucket[i]);
            }
        }
    }
    
    
    free(oldBucket);
}


HashMap * createMap(long capacity) {
    HashMap * new = (HashMap *)malloc(sizeof(HashMap));
    new->buckets = (Pair **) calloc (capacity,sizeof(Pair *));
    new->size = 0;
    new->capacity = capacity;
    new->current = -1;
    return new;
}

void eraseMap(HashMap * map,  char * key) {    
    long idx = hash(key, map->capacity);
    while (map->buckets[idx] != NULL && is_equal(map->buckets[idx]->key, key) == 0)
        idx = (idx + 1) % map->capacity;
    
    if (map->buckets[idx] == NULL) return;

    map->buckets[idx]->key = NULL;

    map->size--;

}

void * searchMap(HashMap * map,  char * key) {   
    long idx = hash(key, map->capacity);
    while (map->buckets[idx] != NULL && is_equal(map->buckets[idx]->key, key) == 0) 
        idx = (idx + 1) % map->capacity;
    
    if (map->buckets[idx] == NULL || map->buckets[idx]->value == NULL) return NULL;
    
    map->current = idx;
    
    return (void *)map->buckets[idx]->value;
}

void * firstMap(HashMap * map) {
long i=0;
while(i<map->capacity){
  if(map->buckets[i]!=NULL){
    if(map->buckets[i]->key==NULL){
    i++;
    }else{
      map->current=i;
      return map->buckets[i]->value;
    }
  }else{
    i++;
  }

}
  return  NULL;
}

void * nextMap(HashMap * map) {
  long posicion=((map->current)+1);
  do{
    if(map->buckets[posicion]!=NULL){
      if(map->buckets[posicion]->key){
        map->current=posicion;
        return map->buckets[posicion]->value;
      }else{
        posicion++;
      }
    }else{
      posicion++;
    }
  }while(posicion<=map->capacity);
    return NULL;
}

int mapsize(HashMap * map){
    return map->size;

}
#ifndef TABLE_H
#define TABLE_H
#include"keyspace.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef struct Table{
	struct KeySpace *ks;
} Table;
void add(Table **a, KeyType, KeyType, InfoType *);
void del(Table *, KeyType);
KeySpace *search(Table *, KeyType);
void print_table(Table *);
void import(Table *, FILE *f);
Table *search_pro(Table *, KeyType, KeyType);
void del_pro(Table *, KeyType);
void freetable(Table *);
#endif

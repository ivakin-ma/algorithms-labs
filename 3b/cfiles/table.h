#ifndef TABLE_H
#define TABLE_H
#include"keyspace.h"
#include"functions.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#define CONST_SUM 1
typedef struct IndexType{
	size_t a;
} IndexType;
typedef struct Table{
	KeySpace *ks;
	IndexType msize;
} Table;
Table *resize(Table *);
unsigned long hash(const char *);
void add(Table **,const unsigned long,const KeyType,InfoType *);
void del(Table *,const KeyType);
KeySpace *search(const Table *,const KeyType);
void print_table(const Table *);
void bin_import(Table **, FILE *);
void bin_export(const Table *, FILE *);
void freetable(Table *);
#endif

#ifndef TABLE_H
#define TABLE_H
#include"keyspace.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CONST_SUM 1
typedef struct IndexType{
	size_t a;
} IndexType;
typedef struct Table{
	KeySpace *ks;
	IndexType msize;
} Table;
Table *resize(Table *);
size_t next_prost(const size_t);
unsigned long hash(const char *);
void init(Table **);
void add(Table **,const unsigned long,const KeyType,InfoType *);
void del(Table *,const KeyType);
KeySpace *search(const Table *,const KeyType);
void print_table(const Table *);
void bin_import(Table *,const FILE *f);
void bin_export(const Table *, FILE *f);
void freetable(Table *);
#endif

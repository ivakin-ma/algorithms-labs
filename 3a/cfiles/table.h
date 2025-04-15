#ifndef TABLE_H
#define TABLE_H
#include"keyspace.h"
#include"inputout.h"
typedef struct Table{
	struct KeySpace *ks;
} Table;
Err add(Table *);
Err del(Table *, KeyType *);
Err search(Table *, KeyType *);
void print_table(Table *);
Err import(Table *, FILE *);
Table *search_pro(Table *);
void freetable(Table *);
#endif

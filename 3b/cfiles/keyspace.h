#ifndef KEYSPACE_H
#define KEYSPACE_H
#include<stdbool.h>
typedef struct BusyType{
	bool b;
} BusyType;
typedef struct KeyType{
	char *s;
} KeyType;
typedef struct InfoType{
	int a;
} InfoType;
typedef struct KeySpace{
	BusyType busy;
	KeyType key;
	InfoType *info;
}KeySpace;
#endif

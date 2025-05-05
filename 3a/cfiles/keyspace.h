#ifndef KEYSPACE_H
#define KEYSPACE_H
typedef struct KeyType{
	char *s;
} KeyType;
typedef struct InfoType{
	unsigned int a;
} InfoType;
typedef struct KeySpace{
	struct KeyType key;
	struct KeyType par;
	struct InfoType *info;
	struct KeySpace *next;
} KeySpace;
#endif

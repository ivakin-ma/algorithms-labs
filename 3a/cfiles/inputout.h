#ifndef INPUTOUT_H
#define INPUTOUT_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#include<readline/readline.h>
#include"table.h"
#include"keyspace.h"
typedef enum Err{
        OK,
        ERROR
}Err;
Err inputn(int *);
Err inputsp(int *);
Err inputkey(Table *, KeyType *);
Err inputpar(Table *, KeyType *);
Err inputinfo(unsigned int *);
Err inputdel(Table*, KeyType *);
#endif

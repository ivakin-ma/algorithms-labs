#ifndef INPUTOUT_H
#define INPUTOUT_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#include<readline/readline.h>
#include"table.h"
Err inputn(int *);
Err inputsp(int *);
Err inputkey(Table *, KeyType *);
Err inputinfo(InfoType *);
Err inputdel(Table*, KeyType *);
#endif

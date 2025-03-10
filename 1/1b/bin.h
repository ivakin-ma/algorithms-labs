#ifndef BIN_H
#define BIN_H
#include<stdio.h>
#include"mat.h"
#include"inputout.h"
typedef struct opis{
	FILE *name;
	long unsigned int pswd;
}opis;
typedef struct bintype{
	FILE *name;
	long unsigned int pswd;
	int len;
	unsigned int *add;
	int count;
	int *line;
}bintype;
Err binprocess(opis *);
Err creator(bintype *t);
#endif

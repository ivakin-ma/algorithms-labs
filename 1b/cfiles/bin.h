#ifndef BIN_H
#define BIN_H
#include<stdio.h>
#include"mat.h"
#include"inputout.h"
typedef struct opis{
	char *name;
	long unsigned int pswd;
}opis;
Err binprocess(FILE *, long unsigned int);
Err creator(FILE *, long unsigned int, Mat *);
#endif

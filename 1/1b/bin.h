#ifndef BIN_H
#define BIN_H
#include<stdio.h>
#include"mat.h"
#include"inputout.h"
typedef struct opis{
	FILE *name;
	long unsigned int pswd;
}opis;
Err binprocess(opis *);
Err creator(FILE *, long unsigned int, Mat *);
#endif

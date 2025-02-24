#ifndef INPUTOUT_H
#define INPUTOUT_H
#include"mat.h"
#include<stdlib.h>
typedef enum Err{
	OK,
	CLOSE
}Err;
Err inputn(int*);
Err inputmat(Mat**);
void printmat(Mat*);
#endif

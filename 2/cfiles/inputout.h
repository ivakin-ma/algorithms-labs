#ifndef INPUTOUT_H
#define INPUTOUT_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef enum Err{
        OK,
        CLOSE
}Err;
Err inputn(int *);
Err inputsp(int *);
#endif

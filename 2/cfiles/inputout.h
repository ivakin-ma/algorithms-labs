#ifndef INPUTOUT_H
#define INPUTOUT_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"commands.h"
typedef enum Err{
        OK,
        CLOSE
}Err;
Err inputn(int *);
Err inputsp(int *);
Err myreadvc(char *, int);
Err myreadsp(node **);
#endif

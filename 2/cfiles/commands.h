#ifndef COMMANDS_H
#define COMMANDS_H
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"inputout.h"
#define CHARSET_NUM "0123456789"
typedef struct stack stack;
Err init(stack**);
Err add(stack**);
int process(stack*);
void freestack(stack**);
#endif

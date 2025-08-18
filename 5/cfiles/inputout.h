#ifndef INPUTOUT_H
#define INPUTOUT_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#include<readline/readline.h>
#include"graph_structures.h"
typedef enum Err{
        OK,
        ERROR
}Err;
Err search_edge(const Graph *, const char *, const char *);
Err search_ver(const Graph *, const char *);
Err inputn(int *);
Err inputsp(int *);
Err inputlvl(int *);
Err input_name(char **);
#endif

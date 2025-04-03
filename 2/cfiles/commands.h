#ifndef COMMANDS_H
#define COMMANDS_H
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define CHARSET_NUM "0123456789"
typedef struct node{
	struct node *prev;
	char value;
} node;
int processa(char *, int);
int processb(node *);
void freenode(node *);
#endif

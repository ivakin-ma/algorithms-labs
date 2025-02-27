#ifndef HEAD_H
#define HEAD_H
#include<stdio.h>
#include<stdlib.h>
typedef struct Line{
	int n;
	int *a;
}Line;
void printline(Line*);
void freeline(Line*);
void processline(Line*);
#endif

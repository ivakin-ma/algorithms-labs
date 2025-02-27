#ifndef MAT_H
#define MAT_H
#include"line.h"
#include<stdio.h>
#include<stdlib.h>
typedef struct Mat{
	int l;
	Line *lines;
}Mat;
void printmat(const Mat*);
void freemat(Mat*);
void process(Mat*);
void copymat(const Mat*, Mat*);
#endif

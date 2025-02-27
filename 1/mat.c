#include"mat.h"
void printmat(const Mat *mat){
	for(int i = 0; i<mat->l; i++){
		printf("%d строка: [", i+1);
		printline(mat->lines+i);
	}
}
void freemat(Mat *mat){
	for(int i = 0; i<mat->l; i++){
		freeline(mat->lines+i);
	}
	free(mat->lines);
	free(mat);
}
void process(Mat *mat){
	for(int i = 0; i<mat->l; i++){
		processline(mat->lines+i);
	}
}
void copymat(const Mat *mat1, Mat *mat2){
	mat2->lines = calloc(mat1->l, sizeof(Line));
	mat2->l = mat1->l;
	for(int i = 0 ; i<mat1->l; i++){
		(&(mat2->lines[i]))->a = calloc((&(mat1->lines[i]))->n, sizeof(int));
		(&(mat2->lines[i]))->n = (&(mat1->lines[i]))->n;
		for(int j = 0; j<(&(mat1->lines[i]))->n; j++){
			(&(mat2->lines[i]))->a[j] = (&(mat1->lines[i]))->a[j];
			printf("%d %d\n", (&(mat2->lines[i]))->a[j], (&(mat2->lines[i]))->a[j]);
		}
	}
}

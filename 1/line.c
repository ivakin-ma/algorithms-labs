#include"head.h"
Err inputn(int *p){
	int s = 0;
	int v = 0;
	do{
		v = 1;
        v = scanf("%d", &s);
		if(v==EOF){
			printf("Выход из программы...\n");
			return CLOSE;
		}
		if(v!=1){
			printf("Некорректный ввод.\n");
			scanf("%*[^\n]");
			continue;
		}
		if(s<1){
			printf("Введено некорректное значение.\n");
			scanf("%*[^\n]");
			continue;
		}
	}while(v!=1||s<1);
	*p = s;
	return OK;
}
Err inputel(int *p){
	int s = 0;
	int v = 0;
	do{
		v = 1;
        v = scanf("%d", &s);
		if(v==EOF){
			printf("Выход из программы...\n");
			return CLOSE;
		}
		if(v!=1){
			printf("Некорректный ввод.\n");
			scanf("%*[^\n]");
			continue;
		}
	}while(v!=1);
	*p = s;
	return OK;
}
Err inputmat(Mat** mat){
	int s;
	int k;
	int el;
	printf("Введите число строк матрицы: ");
    if(inputn(&s)==CLOSE){
        return CLOSE;
    }
    (*mat)->lines = calloc(s, sizeof(Mat));
    (*mat)->l = s;
    for(int i = 0; i<s; i++){
	    printf("Введите число элементов %d-ой строки: ", i+1);
        if(inputn(&k)==CLOSE){
        	return CLOSE;
        }
        (((*mat)->lines)+i)->n = k;
        (((*mat)->lines)+i)->a = calloc(k, sizeof(int));
       	for(int j = 0; j<k;j++){
       		printf("Введите элемент %d: ", j+1);
       		if(inputel(&el)==CLOSE){
       			return CLOSE;
       		}
       		((((*mat)->lines)+i)->a)[j] = el;
       	}
	}
	return OK;
}
void printmat(Mat* mat){
	for(int i = 0; i<(mat->l);i++){
		printf("%d строка:\n[", i+1);
		for(int j = 0; j<((mat)->lines+i)->n-1; j++){
			printf("%d, ", ((mat->lines+i)->a)[j]);
		}
		printf("%d]\n", ((mat->lines+i)->a)[(mat->lines+i)->n-1]);
	}
}
void freemat(Mat* mat){
	for(int i = 0; i<((mat)->l);i++){
		free((mat->lines+i)->a);
	}
	free(mat->lines);
}
void process(Mat *mat){
	int it = -1;
	int jt = -1;
	for(int i = 0; i<mat->l;i++){
		for(int j = 0; j<(mat->lines+i)->n-1; j++){
			if((((mat->lines+i)->a)[j]<((mat->lines+i)->a)[j+1])&&it == -1){
				it = j+i;
			}
			if((((mat->lines+i)->a)[j]>((mat->lines+i)->a)[j+1])){
				jt = j+i;
			}
		}
		if(jt!=-1&&it!=-1){
			int temp = ((mat->lines+i)->a)[jt];
			((mat->lines+i)->a)[jt] = ((mat->lines+i)->a)[it]; 
			((mat->lines+i)->a)[it] = temp;
		}
	}
}

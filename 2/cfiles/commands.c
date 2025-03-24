#include"commands.h"
int processa(char *head, int size){
	int *a = calloc(size, sizeof(int));
	int i = 0;
	while(size>=0){
		if(strrchr(CHARSET_NUM, *(head+sizeof(char)*size))!=NULL){
			a[i]= *(head+sizeof(char)*size) - '0';
			i++;
		}
		else{
			if(*(head+sizeof(char)*size)=='+'){
				a[i-2] = a[i-1]+a[i-2];
				i--;
			}
			else if(*(head+sizeof(char)*size)=='-'){
				a[i-2] = a[i-1]-a[i-2];
				i--;
			}
			else if(*(head+sizeof(char)*size)=='*'){
				a[i-2] = a[i-1]*a[i-2];
				i--;
			}
			else{
				a[i-2] = a[i-1]/a[i-2];
				i--;
			}
		}
		size--;
	}
	int res = a[0];
	free(a);
	return res;
}
int processb(node *top){
	int *a = calloc(10, sizeof(int));
	int i = 0;
	int max = 9;
	int fl = 0;
	do{
		if(i==max){
			a = realloc(a, (max+10)*sizeof(int));
			max+=10;
		}
		if(strrchr(CHARSET_NUM, top->value)!=NULL){
			a[i]= top->value - '0';
			i++;
		}else{
			if(top->value=='+'){
				a[i-2] = a[i-1]+a[i-2];
				i--;
			}
			else if(top->value=='-'){
				a[i-2] = a[i-1]-a[i-2];
				i--;
			}
			else if(top->value=='*'){
				a[i-2] = a[i-1]*a[i-2];
				i--;
			}
			else{
				a[i-2] = a[i-1]/a[i-2];
				i--;
			}
		}
		if(top->prev){
			top = top->prev;
		}
		else{
			fl = 1;
		}
	}while(fl==0);
	int res = a[0];
	free(a);
	return res;
}

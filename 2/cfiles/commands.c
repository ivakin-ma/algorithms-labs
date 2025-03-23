#include"commands.h"
int process(char *head, int size){
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
int intlen(int a){
	int k = 0;
	while(a>0){
		a /= 10;
		k += 1;
	}
	return k;
}

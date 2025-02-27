#include"line.h"
void freeline(Line *line){
	free(line->a);
}
void printline(Line *line){
	for(int i = 0; i<line->n-1; i++){
		printf("%d, ", line->a[i]);
	}
	printf("%d]\n", line->a[line->n-1]);
}
void processline(Line *line){
	int it = -1;
	int jt = -1;
	for(int i  = 0; i<line->n-1; i++){
		if(line->a[i]<line->a[i+1] && it == -1){
			it = i+1;
		}
		if(line->a[i]>line->a[i+1]){
			jt = i+1;
		}
	}
	if(it != -1 && jt != -1){
		int temp = line->a[it];
		line->a[it] = line->a[jt];
		line->a[jt] = temp;
	}
}

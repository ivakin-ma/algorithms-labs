#include"commands.h"
struct stack {
	struct stack *prev;
	char value;
};

Err init(stack **a){
	printf("Введите строку:\n");
	while((*a==NULL)||(*a)->value!='\n'){
		if(add(a)==CLOSE){
			return CLOSE;
		}
	}
	if((*a)->value=='\n'){
		stack *temp = *a;
		*a = (*a)->prev;
		free(temp);
	}
	return OK;
}
Err add(stack **a){
	char c = getchar();
	if(c==EOF){
		return CLOSE;
	}
	if(strchr("0123456789+-/*\n", c)==NULL){
		printf("Введен некорректный символ.\n");
		return CLOSE;
	}
	if(*a==NULL){
		*a = calloc(1, sizeof(stack));
		(*a)->value = c;
	}else{
		stack *temp = calloc(1, sizeof(stack));
		temp->prev = *a;
		temp->value = c;
		*a = temp;
	}
	return OK;
}
int process(stack *top){
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
void freestack(stack **a){
	while(*a){
		stack *temp = *a;
		*a = (*a)->prev;
		free(temp);
	}
	*a = NULL;
}

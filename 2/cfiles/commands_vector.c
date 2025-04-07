#include"commands.h"

struct stack{
	char *s;
};

Err init(stack **a){
	*a = calloc(1, sizeof(stack));
	int size;
	printf("Введите длину строки:\n");
	if(inputn(&size)==CLOSE){
		return CLOSE;
	}
	scanf("%*c");
	(*a)->s = calloc(size+1, sizeof(char));
	printf("Введите строку:\n");
	for(int i = 0; i < size; i++){
		if(add(a)==CLOSE){
			return CLOSE;
		}
	}
}
Err add(stack **a){
	char c = getchar();
	if(c == EOF){
		return CLOSE;
	}
	if(strchr("0123456789-+*/\n", c)==NULL){
		printf("Введен некорректный символ.\n");
		return CLOSE;
	}
	if(c == '\n'){
		return OK;
	}
	(*a)->s[strlen((*a)->s)] = c;
}
int process(stack *head){
	int size = strlen(head->s);
	int *a = calloc(size, sizeof(int));
	int i = 0;
	for(int j = size-1; j>-1; j--){
		if(strrchr(CHARSET_NUM, head->s[j])!=NULL){
			a[i]= (head->s[j]) - '0';
			i++;
		}
		else{
			if(head->s[j]=='+'){
				a[i-2] = a[i-1]+a[i-2];
				i--;
			}
			else if(head->s[j]=='-'){
				a[i-2] = a[i-1]-a[i-2];
				i--;
			}
			else if(head->s[j]=='*'){
				a[i-2] = a[i-1]*a[i-2];
				i--;
			}
			else{
				a[i-2] = a[i-1]/a[i-2];
				i--;
			}
		}
	}
	int res = a[0];
	//free(a);
	return res;
}

void freestack(stack **a){
	free((*a)->s);
	free(*a);
}

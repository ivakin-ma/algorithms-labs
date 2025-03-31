#include"inputout.h"
Err inputsp(int *p){
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
	    if(s<1||s>2){
	        printf("Введено некорректное значение.\n");
	        scanf("%*[^\n]");
	        continue;
	    }
	}while(v!=1||s<1);
	*p = s;
	return OK;
}
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
Err myreadvc(char *s, int n){
	scanf("%*c");
	printf("Введите строку:\n");
	char a = '\0';
	int c = 0;
	while(a!='\n'){
		if(c > n){
			printf("Введено слишком много символов.\n");
			return CLOSE;
		}
		a = getchar();
		if(strstr(&a, "0123456789+-/*")){
			printf("Введен некорректный символ.\n");
			return CLOSE;
		}
		if(a == EOF){
			scanf("%*c");
			printf("Выход из программы...\n");
			return CLOSE;
		}
		s[c] = a;
		c++;
	}
}
Err myreadsp(node **top){
	printf("Введите строку:\n");
	char a = '\0';
	char temp[2] = {0};
	while(a!='\n'){
		a = getchar();
		temp[0] = a;
		temp[1] = '\0';
		if(strstr(temp, "0123456789+-/*")){
			printf("Введен некорректный символ.\n");
			return CLOSE;
		}
		if(a==EOF){
			scanf("%*c");
			printf("Выход из программы...\n");
			return CLOSE;
		}
		node *temp = calloc(1, sizeof(node));
		(*top)->value = a;
		temp->prev = *top;
		*top = temp;
	}
	while((*top)->value=='\0'||(*top)->value=='\n'){
		node *temp = *top;
		(*top) = (*top)->prev;
		free(temp);
	}
}


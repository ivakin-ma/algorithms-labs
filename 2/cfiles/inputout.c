#include"inputout.h"
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

#include"inputout.h"
Err inputn(int *p){
	int s = 0;
	int v = 0;
	do{
	    v = 1;
		v = scanf("%d", &s);
	    if(v==EOF){
	        printf("Выход из программы...\n");
	        return ERROR;
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
Err inputinfo(unsigned int *p){
	long long int s = 0;
	int v = 0;
	do{
		printf("Введите информацию элемента: ");
	    v = 1;
		v = scanf("%lli", &s);
	    if(v==EOF){
	        printf("Выход из программы...\n");
	        return ERROR;
	    }
	    if(v!=1){
	        printf("Некорректный ввод.\n");
	        scanf("%*[^\n]");
	        continue;
	    }
	    if(s<1||s>UINT_MAX){
	        printf("Введено некорректное значение.\n");
	        scanf("%*[^\n]");
	        continue;
	    }
	}while(v!=1||s<1||s>UINT_MAX);
	*p = (unsigned int) s;
	return OK;
}
Err inputsp(int *p){
	int s = 0;
	int v = 0;
	do{
	    v = 1;
		v = scanf("%d", &s);
	    if(v==EOF){
	        printf("Выход из программы...\n");
	        return ERROR;
	    }
	    if(v!=1){
	        printf("Некорректный ввод.\n");
	        scanf("%*[^\n]");
	        continue;
	    }
	    if(s<1||s>7){
	        printf("Введено некорректное значение.\n");
	        scanf("%*[^\n]");
	        continue;
	    }
	}while(v!=1||s<1||s>7);
	*p = s;
	return OK;
}
Err inputkey(Table *t, KeyType *key){
	do{
		key->s = readline("Введите ключ элемента: ");
		if(key->s==NULL){
			printf("Выход из программы...");
			return ERROR;
		}
		if(*key->s=='\0'){
			printf("Ключ не может быть нулевым.\n");
			continue;
		}
		if((t!=NULL)&&(search(t, *key)!=NULL)){
			printf("Этот ключ уже занят.\n");
			continue;
		}
	}while(*key->s=='\0'||(t!=NULL&&(search(t, *key)!=NULL)));
	return OK;
}
Err inputpar(Table *t, KeyType *key){
	do{
		key->s = readline("Введите ключ родительского элемента: ");
		if(key->s==NULL){
			printf("Выход из программы...");
			return ERROR;
		}
		if(*key->s=='\0'){
			free(key->s);
			key->s = NULL;
			return OK;
		}
		if((t!=NULL)&&(search(t, *key)==NULL)){
			printf("Такого ключа нет.\n");
			continue;
		}
	}while(t!=NULL&&search(t, *key)==NULL);
	return OK;
}
Err inputdel(Table *t, KeyType *key){
	do{
		key->s = readline("Введите ключ удаляемого элемента: ");
		if(key->s==NULL){
			printf("Выход из программы...");
			return ERROR;
		}
		if(*key->s=='\0'){
			printf("Ключ не может быть нулевым.");
			continue;
		}
		if((search(t, *key)==NULL)){
			printf("Такого ключа нет.\n");
		}
	}while(search(t, *key)==NULL||*key->s=='\0');
	return OK;
}

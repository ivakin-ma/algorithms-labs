#include"table.h"
#include"readline/readline.h"
Err add(Table *a){
	KeyType *key = calloc(1, sizeof(KeyType));
	int n;
	KeySpace *temp = calloc(1, sizeof(KeySpace));
	key->s = readline("Введите ключ вводимого элемента:\n");
	if(search(a, key)==ERROR){
		KeyType *keypar = calloc(1, sizeof(KeyType));
		keypar->s = readline("Введите родительский ключ:\n");
		if(search(a, keypar)==OK||keypar==NULL){
			temp->key = *key;
			temp->par = *keypar;
			if(inputn(&n)==OK){
				temp->key = *key;
				temp->par = *keypar;
				temp->info = calloc(1, sizeof(InfoType));
				temp->info->a = n;
				if(a->ks==NULL){
					a->ks = temp;
				}else{
					temp->next = a->ks;
					a->ks = temp;
				}
			}else{
				printf("Прерывание работы программы.");
				free(key->s);
				free(keypar->s);
				free(key);
				free(keypar);
				free(temp);
				return ERROR;
			}
		}else{
			printf("Родительского ключа не существует.");
			free(key->s);
			free(keypar->s);
			free(key);
			free(keypar);
			free(temp);
			return ERROR;
		}
	}else{
		free(key->s);
		free(key);
		free(temp);
		printf("Элемент с таким ключом уже существует.");
		return ERROR;
	}
}
Err del

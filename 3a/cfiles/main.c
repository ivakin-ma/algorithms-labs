#include"table.h"
#include"inputout.h"
int main(){
	int sp;
	Table *a = NULL;
	while(1){
		printf("============Меню============\n1. Добавление элемента в таблицу.\n2. Удаление элемента из таблицы.\n");
		printf("3. Вывод таблицы.\n4. Импорт таблицы из текстового файла.\n5. Поиск элементов по диапазону родительского ключа.\n");
		if(inputsp(&sp)==ERROR){
			return 0;
		}
		switch(sp){
			case 1:
				KeyType *key = calloc(1, sizeof(KeyType));
				if(inputkey(a, &key)==ERROR){
					free(key);
					return 0;
				}
				KeyType *par = calloc(1, sizeof(KeyType));
				if(inputpar(a, &par)==ERROR){
					free(par);
					free(key);
					return 0;
				}
				InfoType *info = calloc(1, sizeof(InfoType));
				if(inputinfo(&(info->a))==ERROR){
					return 0;
				}
				add(&a, key, par, info);
				continue;
			case 2:
				if(a==NULL){
					printf("Таблица не инициализированна.\n");
					continue;
				}
				KeyType *temp = calloc(1, sizeof(KeyType));
				temp->s = readline("\n");
				if(temp->s==NULL){
					printf("Выход из программы...\n");
					return 0;
				}
				KeySpace *searched = search(a, temp);
				if(searched==NULL){
					printf("Элемент с таким ключом не найден.\n");
					continue;
				}else{
					del(a, &(searched->key));
				}
			case 3:
				if(a==NULL){
					printf("Таблица не инициализированна.\n");
					continue;
				}
				print_table(a);
				continue;
			case 4:
		        if(a!=NULL){
		                printf("Таблица уже инициализированна.\n");
		                return 0;
		        }
		        char *name = readline("Введите название файла: ");
		        if(name==NULL){
		        	return 0;
		        }
		        FILE *f = fopen(name, "r");
		        if(f==NULL){
		                printf("Ошибка файла.\n");
		                free(name);
		                continue;
		        }
		        a = calloc(1, sizeof(Table));
		        import(a, f);
			case 5:
				if(a==NULL){
					printf("Таблица еще не инициализированна.\n");
					continue;
				}
				KeyType *gran1 = calloc(1, sizeof(KeyType));
				if(inputkey(NULL, &gran1)==ERROR){
					return 0;
				}
				KeyType *gran2 = calloc(1, sizeof(KeyType));
				if(inputkey(NULL, &gran2)==ERROR){
					return 0;
				}
				Table *b = NULL;
				if(gran1>gran2){
					b = search_pro(a, gran2, gran1);
				}else{
					b = search_pro(a, gran1, gran2);
				}
				if(b==NULL){
					printf("Элементы не найдены.\n");
				}else{
					print_table(b);
				}
				continue;
		}
	}
}

#include"table.h"
#include"inputout.h"
int main(){
	int sp;
	Table *a = NULL;
	KeySpace *searched;
	KeyType temp;
	while(1){
		printf("============Меню============\n1. Добавление элемента в таблицу.\n2. Удаление элемента из таблицы.\n");
		printf("3. Вывод таблицы.\n4. Импорт таблицы из текстового файла.\n5. Поиск элементов по диапазону родительского ключа.\n");
		printf("6. Продвинутое удаление.\n7. Завершение программы.\n");
		if(inputsp(&sp)==ERROR){
			return 0;
		}
		switch(sp){
			case 1:
				KeyType key;
				if(inputkey(a, &key)==ERROR){
					freetable(a);
					return 0;
				}
				KeyType par;
				if(inputpar(a, &par)==ERROR){
					free(key.s);
					freetable(a);
					return 0;
				}
				InfoType *info = calloc(1, sizeof(InfoType));
				if(inputinfo(&(info->a))==ERROR){
					freetable(a);
					free(key.s);
					free(par.s);
					free(info);
					return 0;
				}
				add(&a, key, par, info);
				continue;
			case 2:
				if(a==NULL){
					printf("Таблица не инициализированна.\n");
					continue;
				}
				if(inputdel(a, &temp)==ERROR){
					printf("Выход из программы...\n");
					freetable(a);
					return 0;
				}
				searched = search(a, temp);
				del(a, searched->key);
				free(temp.s);
				continue;
			case 3:
				if(a==NULL){
					printf("Таблица не инициализированна.\n");
					continue;
				}
				print_table(a);
				continue;
			case 4:
		        if(a!=NULL){
		        		freetable(a);
		                printf("Таблица уже инициализированна.\n");
		                return 0;
		        }
		        char *name = readline("Введите название файла: ");
		        if(name==NULL){
		        	freetable(a);
		        	printf("Выход из программы...");
		        	return 0;
		        }
		        FILE *f = fopen(name, "r");
		        free(name);
		        if(f==NULL){
		                printf("Ошибка файла.\n");
		                continue;
		        }
		        a = calloc(1, sizeof(Table));
		        import(a, f);
		        continue;
			case 5:
				if(a==NULL){
					printf("Таблица еще не инициализированна.\n");
					continue;
				}
				KeyType gran1;
				if(inputkey(NULL, &gran1)==ERROR){
					freetable(a);
					return 0;
				}
				KeyType gran2;
				if(inputkey(NULL, &gran2)==ERROR){
					free(gran1.s);
					freetable(a);
					return 0;
				}
				Table *b;
				if(strcmp(gran1.s, gran2.s)==1){
					b = search_pro(a, gran2, gran1);
				}else{
					b = search_pro(a, gran1, gran2);
				}
				free(gran1.s);
				free(gran2.s);
				if(b->ks==NULL){
					printf("Элементы не найдены.\n");
				}else{
					print_table(b);
				}
				freetable(b);
				continue;
			case 6:
				if(a==NULL){
				    printf("Таблица не инициализированна.\n");
				    continue;
				}
				KeyType temp;
				if(inputdel(a, &temp)==ERROR){
				    printf("Выход из программы...\n");
				    freetable(a);
				    return 0;
				}
				searched = search(a, temp);
				del_pro(a, searched->key);
				free(temp.s);
				continue;
			case 7:
				freetable(a);
				printf("Выход из программы...\n");
				return 0;
		}
	}
}

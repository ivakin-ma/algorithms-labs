#include"inputout.h"
int main(){
	int sp;
	Table *a = NULL;
	KeySpace *searched;
	KeyType temp;
	char *filename;
	FILE *f;
	while(1){
		printf("============Меню============\n1. Добавление элемента в таблицу.\n2. Удаление элемента из таблицы.\n");
		printf("3. Вывод таблицы.\n4. Импорт таблицы из бинарного файла.\n");
		printf("5. Вывод таблицы в бинарный файл.\n6. Завершение программы.\n");
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
				InfoType *info = calloc(1, sizeof(InfoType));
				if(inputinfo(info)==ERROR){
					freetable(a);
					free(key.s);
					free(info);
					return 0;
				}
				add(&a, hash(key.s), key, info);
				if(a==NULL){
					printf("Переполнение.\n");
					free(key.s);
					free(info);
					return 0;
				}
				continue;
			case 2:
				if(a==NULL){
					printf("Таблица не инициализированна.\n");
					continue;
				}
				if(inputdel(a, &temp)==ERROR){
					printf("Выход из программы...\n");
					if(temp.s){
						free(temp.s);
					}
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
					printf("Таблица уже инициализированна.\n");
					continue;
				}
				filename = readline("Введите имя файла:\n");
				if(!filename){
					printf("Выход из программы...\n");
					return 0;
				}else{
					f = fopen(filename, "rb");
					if(f==NULL){
						printf("Название неверно.\n");
						free(filename);
						return 0;
					}
				}
				bin_import(&a, f);
				free(filename);
				continue;
			case 5:
				if(a==NULL){
				    printf("Таблица не инициализированна.\n");
				    continue;
				}
				filename = readline("Введите имя файла:\n");
				if(!filename){
					printf("Выход из программы...\n");
					return 0;
				}else{
					f = fopen(filename, "wb");
					if(f==NULL){
						printf("Название неверно.\n");
						free(filename);
						return 0;
					}
				}
				bin_export(a, f);
				printf("Экспорт выполнен.\n");
				free(filename);
				continue;
			case 6:
				freetable(a);
				printf("Выход из программы...\n");
				return 0;
		}
	}
}

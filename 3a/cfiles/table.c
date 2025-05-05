#include"table.h"
void add(Table **a, KeyType key, KeyType par, InfoType *info){
	if(*a==NULL){
		*a = calloc(1, sizeof(Table));
		printf("Таблица инициализированна.\n");
		(*a)->ks = calloc(1, sizeof(KeySpace));
		(*a)->ks->key = key;
		(*a)->ks->par = par;
		(*a)->ks->info = info;
	}else{
		KeySpace *temp = calloc(1, sizeof(KeySpace));
		temp->key = key;
		temp->par = par;
		temp->info = info;
		temp->next = (*a)->ks;
		(*a)->ks = temp;
	}
}
void del(Table *a, KeyType key){
	KeySpace *temp = a->ks;
	while(strcmp(temp->next->key.s, key.s)!=0){
		temp = temp->next;
	}
	free(temp->next->info);
	free(temp->next->key.s);
	if(temp->next->par.s){
		free(temp->next->par.s);
	}
	KeySpace *temp1 = temp->next->next;
	free(temp->next);
	temp->next = temp1;
}
KeySpace *search(Table *a, KeyType key){
	KeySpace *temp = a->ks;
	while(temp){
		if(strcmp(temp->key.s,key.s)==0){
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}
void print_table(Table *a){
	KeySpace *temp = a->ks;
	int i = 1;
	while(temp){
		if(temp->par.s==NULL){
			printf("%d-ый элемент:\nKey: %s\nParent key: NULL\nInfo: %d\n", i, temp->key.s, temp->info->a);
		}else{
			printf("%d-ый элемент:\nKey: %s\nParent key: %s\nInfo: %d\n", i, temp->key.s, temp->par.s, temp->info->a);
		}
		i++;
		temp = temp->next;
	}
}
void import(Table *a, FILE *f){
	int mlk;
	fscanf(f, "%d\n",&mlk);
 	char *s = calloc(10+mlk*2+3, sizeof(char));
 	char *key;
 	char *par;
 	unsigned int info;
	while(fscanf(f, "%s[^\n]\n", s)==1){
		if(strstr(s, ",,")==NULL){
			key = strtok(s, ",");
			par = strtok(NULL, ",");
			info = atoi(strtok(NULL, "\n"));
		}else{
			key = strtok(s, ",");
			par = NULL;
			info = atoi(strtok(NULL, ","));
		}
		if(a->ks==NULL){
			a->ks = calloc(1, sizeof(KeySpace));
			a->ks->key.s = calloc(strlen(key)+1, sizeof(char));
			strcpy(a->ks->key.s, key);
			if(par==NULL){
				a->ks->par.s = NULL;
			}else{
				a->ks->par.s = calloc(strlen(par)+1, sizeof(char));
				strcpy(a->ks->par.s, par);
			}
			a->ks->info = calloc(1, sizeof(InfoType));
			a->ks->info->a = info;
		}else{
			KeySpace *temp = calloc(1, sizeof(KeySpace));
			temp->key.s = calloc(strlen(key)+1, sizeof(char));
			strcpy(temp->key.s, key);
			if(par==NULL){
				temp->par.s = NULL;
			}else{
				temp->par.s = calloc(strlen(par)+1, sizeof(char));
				strcpy(temp->par.s, par);
			}
			temp->info = calloc(1, sizeof(InfoType));
			temp->info->a = info;
			temp->next = a->ks;
			a->ks = temp;
		}
		s[0] = '\0';
	}
	free(s);
}
void del_pro(Table *a, KeyType key){
	KeySpace *temp = a->ks;
	while(temp){
		if(temp->par.s!=NULL){
			if(strcmp(temp->par.s, key.s)==0){
				free(temp->par.s);
				temp->par.s = NULL;
			}
		}
	temp = temp->next;
	}
	del(a, key);
}
Table *search_pro(Table *a, KeyType gran1, KeyType gran2){
	Table *b = NULL;
	KeySpace *temp = a->ks;
	KeyType temp1;
	KeyType temp2;
	while(temp){
		if(temp->par.s&&(strcmp(temp->par.s, gran1.s)==1)&&(strcmp(temp->par.s, gran2.s)==-1)){
			temp1.s = calloc(strlen(temp->key.s)+1, sizeof(char));
			strcpy(temp1.s, temp->key.s);
			temp2.s = calloc(strlen(temp->par.s)+1, sizeof(char));
			strcpy(temp2.s, temp->par.s);
			InfoType *temp3 = calloc(1, sizeof(InfoType));
			temp3->a = temp->info->a;
			add(&b, temp1, temp2, temp3);
		}
		temp = temp->next;
	}
	return b;
}
void freetable(Table *a){
	if(a==NULL){
		return;
	}
	KeySpace *temp = a->ks;
	KeySpace *temp1;
	while(temp){
		free(temp->key.s);
		free(temp->par.s);
		free(temp->info);
		temp1 = temp->next;
		free(temp);
		temp = temp1;
	}
	free(a);
}

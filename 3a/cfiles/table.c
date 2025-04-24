#include"table.h"
void add(Table **a, KeyType *key, KeyType *par, InfoType *info){
	if(*a==NULL){
		*a = calloc(1, sizeof(Table));
		printf("Таблица инициализированна.\n");
		(*a)->ks = calloc(1, sizeof(KeySpace));
		(*a)->ks->key = *key;
		(*a)->ks->par = *par;
		(*a)->ks->info = info;
	}else{
		KeySpace *temp = calloc(1, sizeof(KeySpace));
		temp->key = *key;
		temp->par = *par;
		temp->info = info;
		temp->next = (*a)->ks;
		(*a)->ks = temp;
	}
}
void del(Table *a, KeyType *key){
	KeySpace *temp = a->ks;
	while(temp->next->key.s!=key->s){
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
KeySpace *search(Table *a, KeyType *key){
	KeySpace *temp = a->ks;
	while(temp->next){
		if(temp->key.s==key->s){
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}
void print_table(Table *a){
	KeySpace *temp = a->ks;
	int i = 1;
	while(temp!=NULL){
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
	fread(&mlk, sizeof(int), 1, f);
 	char *key = calloc(mlk, sizeof(char));
 	char *par = calloc(mlk, sizeof(char));
 	int info;
	while(fscanf(f, "%s,%s,%d", key, par, &info)){
		if(a->ks==NULL){
			a->ks = calloc(1, sizeof(KeySpace));
			a->ks->key.s = key;
			a->ks->par.s = par;
			a->ks->info->a = info;
		}else{
			KeySpace *temp = calloc(1, sizeof(KeySpace));
			temp->key.s = key;
			temp->par.s = par;
			temp->info->a = info;
			temp->next = a->ks;
			a->ks = temp;
		}
	}
}
void del_pro(Table *a, KeyType *key){
	KeySpace *temp = a->ks;
	while(temp->next){
		if(temp->par.s==key->s){
			temp->par.s = NULL;
		}
	temp = temp->next;
	}
	del(a, key);
}
Table *search_pro(Table *a, KeyType *gran1, KeyType *gran2){
	Table *b = NULL;
	KeySpace *temp = a->ks;
	do{
		if((strcmp(temp->par.s, gran1->s)==1)&&(strcmp(temp->par.s, gran2->s)==-1)){
			add(&b, &temp->key, &temp->par, temp->info);
		}
		if(temp->next){
			temp = temp->next;
		}
	}while(temp->next);
	return b;
}
void freetable(Table *a){
	KeySpace *temp = a->ks;
	KeySpace *temp1 = temp->next;
	do{
		free(temp->key.s);
		free(temp->par.s);
		free(temp->info);
		free(temp);
		temp = temp1;
		if(temp1->next){
			temp1 = temp1->next;
		}
	}while(temp->next);
	free(a);
}

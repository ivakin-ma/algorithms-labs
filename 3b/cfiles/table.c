#include"table.h"
unsigned long int hash(const char *str) {
    unsigned long int hash = 17777852590576505418UL;  // Начальное значение FNV-1a
    int c;
    while ((c = *str++)) {
        hash = (hash ^ c) * 814505675095258777UL;  // FNV-prime
    }
    return hash;
}
void add(Table **a,const unsigned long hash,const KeyType key,InfoType *info){
	if(*a==NULL){
		*a = calloc(1, sizeof(Table));
		(*a)->ks = calloc(2, sizeof(KeySpace));
		(*a)->msize.a = 2;
	}
	while(1){
		unsigned long int f_hash = hash%((*a)->msize.a);
		if((*a)->ks[f_hash].busy.b==0){
			(*a)->ks[f_hash].busy.b = 1;
			(*a)->ks[f_hash].key = key;
			(*a)->ks[f_hash].info = info;
			return;
		}else{
			unsigned long int s_hash = (f_hash + CONST_SUM)%((*a)->msize.a);
			while(s_hash!=f_hash){
				if((*a)->ks[s_hash].busy.b==0){
					(*a)->ks[s_hash].busy.b = 1;
					(*a)->ks[s_hash].key = key;
					(*a)->ks[s_hash].info = info;
					return;
				}
			s_hash = (s_hash + CONST_SUM)%((*a)->msize.a);
			}
			*a = resize(*a);
			if(*a==NULL){
				return;
			}
		}
	}
}
Table *resize(Table *a){
	Table *b = calloc(1, sizeof(Table));
	size_t next_size = next_prost(a->msize.a);
	if(next_size==SIZE_MAX){
		freetable(a);
		return NULL;
	}
	b->msize.a = next_size;
	b->ks = calloc(next_size, sizeof(KeySpace));
	for(size_t i = 0; i<a->msize.a; i++){
		if(a->ks[i].busy.b==0){
			continue;
		}else{
			add(&b, hash(a->ks[i].key.s), a->ks[i].key, a->ks[i].info);
		}
	}
	free(a->ks);
	free(a);
	return b;
}
void del(Table *a,const KeyType key){
	unsigned long int del_hash = hash(key.s)%(a->msize.a);
	while(1){
		if(a->ks[del_hash].busy.b ==1&&strcmp(a->ks[del_hash].key.s, key.s)==0){
			a->ks[del_hash].busy.b = 0;
			free(a->ks[del_hash].key.s);
			free(a->ks[del_hash].info);
		}
		del_hash = (del_hash + CONST_SUM)%(a->msize.a);	}
}
KeySpace *search(const Table *a,const KeyType key){
	unsigned long int search_hash = hash(key.s)%(a->msize.a);
	unsigned long int f_hash = search_hash;
	while(1){
		if(a->ks[search_hash].busy.b==1&&strcmp(a->ks[search_hash].key.s, key.s)==0){
			return &(a->ks[search_hash]);
		}
		search_hash = (search_hash + CONST_SUM)%(a->msize.a);
		if(search_hash==f_hash){
			return NULL;
		}
	}
}
void print_table(const Table *a){
	for(size_t i = 0; i<a->msize.a; i++){
		if(a->ks[i].busy.b==1){
			printf("%zu элемент:\nКлюч: %s\nИнформация: %u\n", i+1, a->ks[i].key.s, a->ks[i].info->a);
		}else{
			printf("%zu элемент отсутствует.\n", i+1);
		}
	}
}
void bin_import(Table **a, FILE *f){
	unsigned long int passwd = 17777852590576505418UL;
	unsigned long int pass;
	fseek(f, 0, SEEK_SET);
	fread(&pass, sizeof(unsigned long int), 1, f);
	if(pass!=passwd){
		printf("Ошибка файла.\n");
		fclose(f);
		return;
	}
	*a = calloc(1, sizeof(Table));
	(*a)->msize.a = 2;
	(*a)->ks = calloc(2, sizeof(KeySpace));
	unsigned int ad1;
	unsigned int ad2;
	InfoType *info;
	fread(&ad1, sizeof(unsigned int), 1, f);
	unsigned int ad_max = ad1;
	unsigned int i = 0;
	fseek(f, sizeof(unsigned long int), SEEK_SET);
	while((i+2)*8<ad_max){
		i++;
		fread(&ad1, sizeof(unsigned int), 1, f);
		info = calloc(1, sizeof(InfoType));
		fread(&(info->a), sizeof(unsigned int), 1, f);
		if(i*8+1<ad_max){
			fread(&ad2, sizeof(unsigned int), 1, f);
			fseek(f, ad1, SEEK_SET);
			KeyType key;
			key.s = calloc(ad2-ad1+1, sizeof(char));
			fread(key.s, sizeof(char), ad2-ad1+1, f);
			key.s[ad2-ad1] = '\0';
			add(a, hash(key.s), key, info);
			fseek(f, i*8+sizeof(long unsigned int), SEEK_SET);
			ad1 = ad2;
		}
	}
	fseek(f, 0, SEEK_END);
	ad2 = ftell(f);
	KeyType key;
	key.s = calloc(ad2-ad1+1, sizeof(char));
	fseek(f, ad1, SEEK_SET);
	fread(key.s, sizeof(char), ad2-ad1+1, f);
	key.s[ad2-ad1] = '\0';
	add(a, hash(key.s), key, info);
}
void bin_export(const Table *a, FILE *f){
	unsigned long int passwd = 17777852590576505418UL;
	fwrite(&passwd, sizeof(unsigned long int), 1, f);
	size_t counter = 0;
	for(size_t i = 0;i<a->msize.a; i++){
		if(a->ks[i].busy.b==1){
			counter++;
		}
	}
	unsigned int add = sizeof(unsigned long int)+counter*sizeof(unsigned int)*2;
	for(size_t i = 0; i<a->msize.a; i++){
		if(a->ks[i].busy.b==0){
			continue;
		}else{
			fwrite(&add, sizeof(unsigned int), 1, f);
			fwrite(&(a->ks[i].info->a), sizeof(unsigned int), 1, f);
			add+=strlen(a->ks[i].key.s);
		}
	}
	for(size_t i = 0; i<a->msize.a; i++){
		if(a->ks[i].busy.b==0){
			continue;
		}else{
			fwrite(a->ks[i].key.s, sizeof(char), strlen(a->ks[i].key.s), f);
		}
	}
}
void freetable(Table *a){
	if(a==NULL){
		return;
	}
	for(size_t i = 0; i<a->msize.a; i++){
		if(a->ks[i].busy.b==0){
			continue;
		}else{
			free(a->ks[i].key.s);
			free(a->ks[i].info);
		}
	}
	free(a->ks);
	free(a);
}

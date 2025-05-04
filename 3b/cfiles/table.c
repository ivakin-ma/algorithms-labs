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
		}
	}
}
Table *resize(Table *a){
	Table *b = calloc(1, sizeof(Table));
	size_t next_size = next_prost(a->msize.a);
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
void del(Table *,const KeyType);
KeySpace *search(const Table *,const KeyType);
void print_table(const Table *);
void bin_import(Table *,const FILE *f);
void bin_export(const Table *, FILE *f);
void freetable(Table *);

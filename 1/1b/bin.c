#include"bin.h"
Err binprocess(opis *op){
	int n;
	long unsigned int pas;
	unsigned int adr1;
	int l;
	int temp1;
	int temp2;
	int it = -1;
	int itc;
	int jt = -1;
	int jtc;
	FILE *f = op->name;
	long unsigned int pswd = op->pswd;
	fseek(f, 0, SEEK_SET);
	fread(&pas, sizeof(long unsigned int), 1, f);
	if(pas != pswd){
		printf("Неверный файл.\n");
		return CLOSE;
	}
	fread(&n, sizeof(int), 1, f);
	for(int i = 0; i<n; i++){
		fseek(f, 8+4+8*i, SEEK_SET);
		fread(&adr1, sizeof(unsigned int), 1, f);
		fseek(f, adr1, SEEK_SET);
		fread(&l, sizeof(int), 1, f);
		fread(&temp1, sizeof(int), 1, f);
		for(int j = 1; j<l; j++){
			fread(&temp2, sizeof(int), 1, f);
			if(it==-1&&temp2>temp1){
				it = j+1;
				itc = temp2;
			}
			if(temp2<temp1){
				jt = j+1;
				jtc = temp2;
			}
			temp1 = temp2;
		}
		if(it!=-1&&jt!=-1){
			fseek(f, adr1+4+it+4, SEEK_SET);
			fwrite(&itc, sizeof(int), 1, f);
			fseek(f, adr1+4+jt+4, SEEK_SET);
			fwrite(&jtc, sizeof(int), 1, f);
		}
	}
}
Err creator(bintype *t){ //вспомогательная функция для создания бинарного файла
	fwrite(&(t->pswd), sizeof(long unsigned int), 1, t->name);
	fwrite(&(t->len), sizeof(int), 1, t->name);
	for(int i = 0; i<t->len; i++){
		fwrite(&(t->add[i]), sizeof(unsigned int), 1, t->name);
	}
	for(int i =0; i<t->count; i++){
		fwrite(&(t->line[i]), sizeof(int), 1, t->name);
	}
}

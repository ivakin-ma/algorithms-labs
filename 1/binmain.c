#include"inputout.h"
#include"mat.h"
#include"line.h"
#include"bin.h"
int main(){
		long unsigned int pswd = 17777852590576505418UL;
        Mat *mat = calloc(1, sizeof(Mat));
        if(inputmat(mat)==CLOSE){
                return 0;
        }
        char *name;
        printf("Введите название файла: ");
        scanf("%s", name);
        FILE *f = fopen(name, "w");
        creator(f, pswd, mat);
        freemat(mat);
        printf("%zu %zu", sizeof(Mat), sizeof(Line));
}

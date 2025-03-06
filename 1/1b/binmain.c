#include"inputout.h"
#include"mat.h"
#include"line.h"
#include"bin.h"
#include"readline/readline.h"
int main(){
		long unsigned int pswd = 17777852590576505418UL;
        // Mat *mat = calloc(1, sizeof(Mat));
        // if(inputmat(mat)==CLOSE){
        //         return 0;
        // }
        char *name;
        name = readline("Введите название файла: ");
        FILE *f = fopen(name, "rb");
        binprocess(f, pswd);
        // creator(f, pswd, mat);
        // freemat(mat);
}

#include"inputout.h"
#include"commands.h"
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char *argv[]){
	int sp = getopt(argc, argv, "ab");
	if(getopt(argc, argv, "ab")!=-1){
		printf("Введено слишком много ключей.");
		return 0;
	}
	switch (sp){
		case 'a':
			int n;
			printf("Введите длину строки: ");
			if(inputn(&n)==CLOSE){
				return 0;
			}
			char *s = calloc(n, sizeof(char));
			if(myreadvc(s, n)==CLOSE){
				free(s);
				return 0;
			}
			int ans = process(s, n-1);
			printf("%d\n", ans);
		case 'b':
			//
	}
}

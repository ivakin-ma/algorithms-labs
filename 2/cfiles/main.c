#include"inputout.h"
#include"commands.h"
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char *argv[]){
	int sp;
	if((sp = getopt(argc, argv, "ab"))==-1){
		printf("Введено слишком мало ключей.");
		return 0;
	}
	int ans;
	switch (sp){
		case 'a':
			int n;
			printf("Введите длину строки: ");
			if(inputn(&n)==CLOSE){
				return 0;
			}
			char *s = calloc(n+1, sizeof(char));
			if(myreadvc(s, n)==CLOSE){
				free(s);
				return 0;
			}
			ans = processa(s, n-1);
			printf("Ans: %d\n", ans);
			free(s);
			return 0;
		case 'b':
			node *top = calloc(1, sizeof(node));
			top->prev = NULL;
			myreadsp(&top);
			ans = processb(top);
			printf("Ans: %d\n", ans);
			freenode(top);
			return 0;
	}
}

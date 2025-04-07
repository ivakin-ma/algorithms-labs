#include"commands.h"
#include<stdlib.h>
int main(){
	stack *a = NULL;
	if(init(&a)==CLOSE){
		printf("Выход из программы...\n");
		return 0;
	}
	int ans = process(a);
	printf("Ответ: %d\n", ans);
	freestack(&a);
}

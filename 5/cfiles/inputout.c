#include"inputout.h"
Err inputn(int *p){
	int s = 0;
	int v = 0;
	do{
	    v = 1;
		v = scanf("%d", &s);
	    if(v==EOF){
	        printf("Выход из программы...\n");
	        return ERROR;
	    }
	    if(v!=1){
	        printf("Некорректный ввод.\n");
	        scanf("%*[^\n]");
	        continue;
	    }
	    if(s<1){
	        printf("Введено некорректное значение.\n");
	        scanf("%*[^\n]");
	        continue;
	    }
	}while(v!=1||s<1);
	*p = s;
	return OK;
}
Err input_name(char **name){
	do{
		*name = readline("");
		if(name==NULL){
			printf("Выход из программы...");
			return ERROR;
		}
		if(**name=='\0'){
			printf("Имя не может быть нулевым.\n");
			continue;
		}
	}while(**name=='\0');
	return OK;
}
Err search_edge(const Graph *g, const char *name1, const char *name2){
	if(g->vertices==NULL){
		return ERROR;
	}
	int i = 0;
	Vertex *temp = &(g->vertices[i]);
	while(strcmp(temp->name_cur, name1)!=0){
		i++;
		temp = &(g->vertices[i]);
	}
	if(temp->edges==NULL){
		return ERROR;
	}
	Edge *temp_edge = temp->edges;
	while(strcmp(temp_edge->name_to, name2)!=0){
		if(temp_edge->next){
			temp_edge = temp_edge->next;
		}else{
			return ERROR;
		}
	}
	return OK;
}
Err search_ver(const Graph *g, const char *name1){
	if(g->vertices==NULL){
		return ERROR;
	}
	for(int i = 0; i<g->vertex_count; i++){
		if(strcmp(g->vertices[i].name_cur, name1)==0){
			return OK;
		}
	}
	return ERROR;
}
Err inputsp(int *p){
	int s = 0;
	int v = 0;
	do{
	    v = 1;
		v = scanf("%d", &s);
	    if(v==EOF){
	        printf("Выход из программы...\n");
	        return ERROR;
	    }
	    if(v!=1){
	        printf("Некорректный ввод.\n");
	        scanf("%*[^\n]");
	        continue;
	    }
	    if(s<1||s>12){
	        printf("Введено некорректное значение.\n");
	        scanf("%*[^\n]");
	        continue;
	    }
	}while(v!=1||s<1||s>12);
	*p = s;
	return OK;
}
Err inputlvl(int *p){
	int s = 0;
	int v = 0;
	do{
	    v = 1;
		v = scanf("%d", &s);
	    if(v==EOF){
	        printf("Выход из программы...\n");
	        return ERROR;
	    }
	    if(v!=1){
	        printf("Некорректный ввод.\n");
	        scanf("%*[^\n]");
	        continue;
	    }
	    if(s<-10||s>10){
	        printf("Введено некорректное значение.\n");
	        scanf("%*[^\n]");
	        continue;
	    }
	}while(v!=1||s<-10||s>10);
	*p = s;
	return OK;
}

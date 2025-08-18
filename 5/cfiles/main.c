#include "graph.h"
#include "inputout.h"
int main() {
    Graph *g = calloc(1, sizeof(Graph));
    int sp;
    char *name = NULL;
    char *name1 = NULL;
    char *name2 = NULL;
    int lvl;
    while (1) {
        printf("============ Меню ============\n");
        printf("1. Вывести списки смежности.\n");
        printf("2. Добавить вершину.\n");
        printf("3. Добавить ребро.\n");
        printf("4. Удалить вершину.\n");
        printf("5. Удалить ребро.\n");
        printf("6. Переименовать человека.\n");
        printf("7. Изменить вес ребра.\n");
        printf("8. Обход: знакомы не более чем через K рукопожатий (DFS).\n");
        printf("9. Кратчайшая цепочка (Беллман–Форд).\n");
        printf("10. Особая операция (Флойд–Уоршелл: максимальная цепочка).\n");
        printf("11. Экспорт в DOT.\n");
        printf("12. Выход.\n");
        inputsp(&sp);
        switch (sp) {
            case 1:
            	if(g->vertices==NULL){
            		printf("Граф пуст.\n");
            		continue;
            	}
                print_graph(g);
                continue;
            case 2:
            	printf("Введите имя вершины: ");
            	if(input_name(&name)==ERROR){
            		free_graph(g);
            		return 0;
            	}
            	if(search_ver(g, name)==OK){
            		printf("Имя уже занято.\n");
            		free(name);
            		name = NULL;
            		continue;
            	}
            	add_ver(g, name);
            	free(name);
            	name = NULL;
            	continue;
            case 3:
            	if(g->vertices==NULL){
            		printf("Граф пуст.\n");
            		continue;
            	}
            	printf("Введите имена вершин и уроень связи.\n");
            	if(input_name(&name1)==ERROR||input_name(&name2)==ERROR||inputlvl(&lvl)==ERROR){
            		free_graph(g);
            		return 0;
            	}
            	if(search_ver(g, name1)==ERROR||search_ver(g, name2)==ERROR||search_edge(g, name1, name2)==OK){
            		printf("Невозможно проложить ребро между выбранными вершинами.\n");
            		free(name1);
            		free(name2);
            		name1 = name2 = NULL;
            		continue;
            	}
            	add_edg(g, name1, name2, lvl);
            	free(name1);
            	free(name2);
            	name1 = name2 = NULL;
            	continue;
            case 4:
            	printf("Ввкдите имя вершины: ");
            	if(input_name(&name)==ERROR){
            		free_graph(g);
            		return 0;
            	}
            	if(search_ver(g, name)==ERROR){
            		printf("Такой вершины нет.\n");
            		free(name);
            		name = NULL;
            		continue;
            	}
            	del_ver(g, name);
            	free(name);
            	name = NULL;
            	continue;
            case 5:
            	printf("Введите имена вершин.\n");
            	if(input_name(&name1)==ERROR||input_name(&name2)==ERROR){
            		free_graph(g);
            		return 0;
            	}
            	if(search_ver(g, name1)==ERROR||search_ver(g, name2)==ERROR||search_edge(g, name1, name2)==ERROR){
            		printf("Удалить указанное ребро невозможно.\n");
            		free(name1);
            		free(name2);
            		name1 = name2 = NULL;
            		continue;
            	}
            	del_edg(g, name1, name2);
            	free(name1);
            	free(name2);
            	name1 = name2 = NULL;
            	continue;
            case 6:
            	printf("Введите имя вершины, затем новое имя.\n");
            	if(input_name(&name1)==ERROR||input_name(&name2)==ERROR){
            		free_graph(g);
            		return 0;
            	}
            	if(search_ver(g, name1)==ERROR||search_ver(g, name2)==OK){
            		printf("Указанное переименование невозможно.\n");
            		free(name1);
            		free(name2);
            		name1 = name2 = NULL;
            		continue;
            	}
            	change_name(g, name1, name2);
            	free(name1);
            	free(name2);
            	name1 = name2 = NULL;
            	continue;
            case 7:
            	printf("Введите вершины, соединенные ребром, затем новый уровень связи.\n");
            	if(input_name(&name1)==ERROR||input_name(&name2)==ERROR||inputlvl(&lvl)==ERROR){
					free_graph(g);
            		return 0;
            	}if(search_ver(g, name1)==ERROR||search_ver(g, name2)==ERROR||search_edge(g, name1, name2)==ERROR){
            		printf("Указанное ребро не найдено.\n");
            		free(name1);
            		free(name2);
            		name1 = name2 = NULL;
            		continue;
            	}
            	change_lvl(g, name1, name2, lvl);
            	free(name1);
            	free(name2);
            	name1 = name2 = NULL;
            	continue;
            case 8:
            	printf("Введите глубину поиска, затем имя вершины.\n");
            	int max;
            	if(inputn(&max)==ERROR||input_name(&name)==ERROR){
            		free_graph(g);
            		return 0;
            	}
            	if(search_ver(g, name)==ERROR){
            		printf("Указанная вершина не найдена.\n");
            		free(name);
            		name = NULL;
            		continue;
            	}
            	int count;
            	char **dfs_ans = dfs(g, name, max, &count);
            	if(dfs_ans==NULL){
            		printf("Граф отсутствует.\n");
            		free(name);
            		name = NULL;
            		continue;
            	}
            	for(int i = 0; i<count; i++){
            		printf("%d. %s\n", i+1, dfs_ans[i]);
            		free(dfs_ans[i]);
            	}
            	free(name);
            	free(dfs_ans);
            	name = NULL;
            	continue;
            case 9:
            	printf("Введите имена вершин.\n");
            	if(input_name(&name1)==ERROR||input_name(&name2)==ERROR){
            		free_graph(g);
            		return 0;
            	}
            	if(search_ver(g, name1)==ERROR||search_ver(g, name2)==ERROR){
            		printf("Указанные вершины не найдены.\n");
            		free(name1);
            		free(name2);
            		name1 = name2 = NULL;
            		continue;
            	}
            	int sum;
            	int dl;
            	char **ans = bellman_ford(g, name1, name2, &sum, &dl);
            	if(ans == NULL){
            		free(name1);
            		free(name2);
            		name1 = name2 = NULL;
            		continue;
            	}
            	for(int i = 0; i < dl; i++){
            		printf("%s -> ", ans[i]);
            		free(ans[i]);
            	}
            	printf("%s\n%d\n", name2, sum);
            	free(name1);
            	free(name2);
            	free(ans);
            	name1 = name2 = NULL;
            	continue;
			case 10:
			    if (g->vertex_count == 0) {
			        printf("Граф пуст.\n");
			        continue;
			    }
			    printf("Введите имя вершины: ");
			    if (input_name(&name)==ERROR) {
			        free_graph(g);
			        return 0;
			    }
			    char *res = floyd(g, name);
			    printf("%s\n", res);
			    free(res);
			    free(name);
			    name = NULL;
			    continue;
			case 11:
			    if (g->vertex_count == 0) {
			        printf("Граф пуст.\n");
			        continue;
			    }
			    printf("Введите имя dot-файла: ");
			    if (input_name(&name)==ERROR) {
			        free_graph(g);
			        return 0;
			    }
			    if (export_to_dot(g, name) == 0) {
			        printf("DOT сохранён в %s.\n", name);
			        printf("Чтобы получить картинку: dot -Tpng %s -o out.png\n", name);
			    }
			    continue;
            case 12:
            	free_graph(g);
            	printf("Выход из программы...\n");
            	return 0;
        }
    }
}

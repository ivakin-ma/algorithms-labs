#include"graph.h"
void add_ver(Graph *g, const char *name){
	if(g->vertices==NULL){
		g->vertices = calloc(1, sizeof(Vertex));
		g->vertices[0].name_cur = strdup(name);
		g->vertex_count = 1;
		return;
	}
	else{
		g->vertex_count++;
		g->vertices = realloc(g->vertices, g->vertex_count * sizeof(Vertex));
		g->vertices[g->vertex_count-1].name_cur = strdup(name);
		g->vertices[g->vertex_count-1].edges = NULL;
		
	}
}
void add_edg(Graph *g, const char *name1, const char *name2, const int lvl){
	int i = 0;
	Vertex *temp = &(g->vertices[i]);
	while(strcmp(temp->name_cur, name1)!=0){
		i++;
		temp = &(g->vertices[i]);
	}
	if(temp->edges==NULL){
		temp->edges = calloc(1, sizeof(Edge));
		temp->edges->name_to = strdup(name2);
		temp->edges->lvl = lvl;
	}else{
		Edge *temp_edge = calloc(1, sizeof(Edge));
		temp_edge->lvl = lvl;
		temp_edge->name_to = strdup(name2);
		temp_edge->next = temp->edges;
		temp->edges = temp_edge;
	}
	i = 0;
	temp = &(g->vertices[i]);
	while(strcmp(temp->name_cur, name2)!=0){
		i++;
		temp = &(g->vertices[i]);
	}
	if(temp->edges==NULL){
		temp->edges = calloc(1, sizeof(Edge));
		temp->edges->name_to = strdup(name1);
		temp->edges->lvl = lvl;
	}else{
		Edge *temp_edge = calloc(1, sizeof(Edge));
		temp_edge->lvl = lvl;
		temp_edge->name_to = strdup(name1);
		temp_edge->next = temp->edges;
		temp->edges = temp_edge;
	}
}
void del_edg(Graph *g, const char *name1, const char *name2){
	int i = 0;
	Vertex *temp = &(g->vertices[i]);
	while(strcmp(temp->name_cur, name1)!=0){
		i++;
		temp = &(g->vertices[i]);
	}
	if(strcmp(temp->edges->name_to, name2)==0){
		if(temp->edges->next){
			Edge *new = temp->edges->next;
			free(temp->edges->name_to);
			free(temp->edges);
			temp->edges = new;
		}else{
			free(temp->edges->name_to);
			free(temp->edges);
			temp->edges = NULL;
		}
	}else{
		Edge *temp_edge = temp->edges;
		while(strcmp(temp_edge->next->name_to, name2)!=0){
			temp_edge = temp_edge->next;
		}
		Edge *new = temp_edge->next->next;
		free(temp_edge->next->name_to);
		free(temp_edge->next);
		temp_edge->next = new;
	}
	i = 0;
	temp = &(g->vertices[i]);
	while(strcmp(temp->name_cur, name2)!=0){
		i++;
		temp = &(g->vertices[i]);
	}
	if(strcmp(temp->edges->name_to, name1)==0){
		if(temp->edges->next){
			Edge *new = temp->edges->next;
			free(temp->edges->name_to);
			free(temp->edges);
			temp->edges = new;
		}else{
			free(temp->edges->name_to);
			free(temp->edges);
			temp->edges = NULL;
		}
	}else{
		Edge *temp_edge = temp->edges;
		while(strcmp(temp_edge->next->name_to, name1)!=0){
			temp_edge = temp_edge->next;
		}
		Edge *new = temp_edge->next->next;
		free(temp_edge->next->name_to);
		free(temp_edge->next);
		temp_edge->next = new;
	}
}
void change_lvl(Graph *g, const char *name1, const char *name2, const int lvl){
	int i = 0;
	Vertex *temp = &(g->vertices[i]);
	while(strcmp(temp->name_cur, name1)!=0){
		i++;
		temp = &(g->vertices[i]);
	}
	Edge *temp_edge = temp->edges;
	while(strcmp(temp_edge->name_to, name2)!=0){
		temp_edge = temp_edge->next;
	}
	temp_edge->lvl = lvl;
	i = 0;
	temp = &(g->vertices[i]);
	while(strcmp(temp->name_cur, name2)!=0){
		i++;
		temp = &(g->vertices[i]);
	}
	temp_edge = temp->edges;
	while(strcmp(temp_edge->name_to, name1)!=0){
		temp_edge = temp_edge->next;
	}
	temp_edge->lvl = lvl;
}
void change_name(Graph *g, const char *name1, const char *name2){
	int i = 0;
	Vertex *temp = &(g->vertices[i]);
	while(strcmp(temp->name_cur, name1)!=0){
		i++;
		temp = &(g->vertices[i]);
	}
	free(temp->name_cur);
	temp->name_cur = strdup(name2);
	for (int j = 0; j < g->vertex_count; j++){
        Edge *temp_edge = g->vertices[j].edges;
        while (temp_edge){
            if (strcmp(temp_edge->name_to, name1) == 0){
                free(temp_edge->name_to);
                temp_edge->name_to = strdup(name2);
            }
            temp_edge = temp_edge->next;
        }
    }
}
void print_graph(const Graph *g){
	for (int j = 0; j < g->vertex_count; j++){
		printf("%s: ", g->vertices[j].name_cur);
        Edge *temp_edge = g->vertices[j].edges;
        while (temp_edge){
            printf("-> %s(%d) ", temp_edge->name_to, temp_edge->lvl);
            temp_edge = temp_edge->next;
        }
        printf("\n");
    }
}
void del_ver(Graph *g, const char *name){
	int i = 0;
	Vertex *temp = &(g->vertices[i]);
	while(strcmp(temp->name_cur, name)!=0){
		i++;
		temp = &(g->vertices[i]);
	}
	if(temp->edges==NULL){
		free(temp->name_cur);
		for(int j = i; j<g->vertex_count-1; j++){
			g->vertices[j] = g->vertices[j+1];
		}
		g->vertex_count--;
		g->vertices = realloc(g->vertices, g->vertex_count * sizeof(Vertex));
		return;
	}else{
		while(temp->edges){
			del_edg(g, name, temp->edges->name_to);
		}
		free(temp->name_cur);
		for(int j = i; j<g->vertex_count; j++){
			g->vertices[j] = g->vertices[j+1];
		}
		g->vertex_count--;
		g->vertices = realloc(g->vertices, g->vertex_count * sizeof(Vertex));
	}
}
void free_edges(Edge *e) {
    while (e) {
        Edge *next = e->next;
        free(e->name_to);
        free(e);
        e = next;
    }
}
void free_vertex(Vertex *v) {
    if (!v) return;
    free(v->name_cur);
    free_edges(v->edges);
    v->edges = NULL;
}
void free_graph(Graph *g){
    if (!g) return;
    if (!g->vertices){
        free(g);
        return;
    }
    for (int i = 0; i < g->vertex_count; i++){
        free_vertex(&(g->vertices[i]));
    }
    free(g->vertices);
    g->vertices = NULL;
    g->vertex_count = 0;
    free(g);
}
int str_in_array(const char *s, char *const *arr, int n) {
    for (int i = 0; i < n; ++i)
        if (arr[i] && strcmp(arr[i], s) == 0) return 1;
    return 0;
}

static void dfs_visit(const Graph *g, const Vertex *v, int depth, int max_depth, char ***visited, int *visited_count){
    if (!v) return;
    if (depth > max_depth) return;
    if (str_in_array(v->name_cur, *visited, *visited_count)) return;
    char **tmp = realloc(*visited, (size_t)(*visited_count + 1) * sizeof(char*));
    if (!tmp) return;
    *visited = tmp;
    (*visited)[*visited_count] = strdup(v->name_cur);
    if (!(*visited)[*visited_count]) return;
    (*visited_count)++;
    for (Edge *e = v->edges; e; e = e->next) {
        for (int i = 0; i < g->vertex_count; ++i) {
            if (strcmp(g->vertices[i].name_cur, e->name_to) == 0) {
                dfs_visit(g, &g->vertices[i], depth + 1, max_depth, visited, visited_count);
                break;
            }
        }
    }
}

char **dfs(const Graph *g, const char *start, int max_depth, int *out_count){
    if (out_count) *out_count = 0;
    const Vertex *start_v = NULL;
    for (int i = 0; i < g->vertex_count; ++i) {
        if (strcmp(g->vertices[i].name_cur, start) == 0) {
            start_v = &g->vertices[i];
            break;
        }
    }
    if (!start_v) return NULL;
    char **visited = NULL;
    int visited_count = 0;
    dfs_visit(g, start_v, 0, max_depth, &visited, &visited_count);
    if (out_count) *out_count = visited_count;
    return visited;
}
char **bellman_ford(const Graph *g, const char *name1, const char *name2, int *sum, int *dl) {
    int V = g->vertex_count;
    int *dist   = calloc(V, sizeof(int));
    int *parent = calloc(V, sizeof(int));
    for (int i = 0; i < V; ++i) { dist[i] = INT_MAX; parent[i] = -1; }
    int start_idx = -1, finish_idx = -1;
    for (int i = 0; i < V; ++i) {
        if (start_idx  < 0 && strcmp(g->vertices[i].name_cur, name1) == 0) start_idx  = i;
        if (finish_idx < 0 && strcmp(g->vertices[i].name_cur, name2) == 0) finish_idx = i;
    }
    dist[start_idx] = 0;
    for (int k = 0; k < V - 1; ++k) {
        int changed = 0;
        for (int u = 0; u < V; ++u) {
            if (dist[u] == INT_MAX) continue;
            for (Edge *e = g->vertices[u].edges; e; e = e->next) {
                int v = -1;
                for (int i = 0; i < V; ++i) {
                    if (strcmp(g->vertices[i].name_cur, e->name_to) == 0) { v = i; break; }
                }
                if (v != -1 && dist[u] + e->lvl < dist[v]) {
                    dist[v] = dist[u] + e->lvl;
                    parent[v] = u;
                    changed = 1;
                }
            }
        }
        if (!changed) break;
    }
    for (int u = 0; u < V; ++u) {
        if (dist[u] == INT_MAX) continue;
        for (Edge *e = g->vertices[u].edges; e; e = e->next) {
            int v = -1;
            for (int i = 0; i < V; ++i) {
                if (strcmp(g->vertices[i].name_cur, e->name_to) == 0) { v = i; break; }
            }
            if (v != -1 && dist[u] + e->lvl < dist[v]) { free(dist); free(parent); return NULL; }
        }
    }
    if (dist[finish_idx] == INT_MAX) { free(dist); free(parent); return NULL; }
    if (start_idx == finish_idx) {
        *sum = 0; *dl = 0;
        free(dist); free(parent);
        return NULL;
    }
    *sum = dist[finish_idx];
    char **rev = NULL;
    int rlen = 0;
    int v = finish_idx;

    while (parent[v] != -1) {                  // кладём только родителей, без finish
        char **tmp = realloc(rev, (rlen + 1) * sizeof(char*));
        if (!tmp) { for (int i = 0; i < rlen; ++i) free(rev[i]); free(rev); free(dist); free(parent); return NULL; }
        rev = tmp;
        int p = parent[v];
        rev[rlen++] = strdup(g->vertices[p].name_cur);
        v = p;
    }
    char **ans = NULL;
    if (rlen > 0) {
        ans = calloc(rlen, sizeof(char*));
        if (!ans) { for (int i = 0; i < rlen; ++i) free(rev[i]); free(rev); free(dist); free(parent); return NULL; }
        for (int i = 0; i < rlen; ++i) {
            ans[i] = rev[rlen - 1 - i];
        }
    }
    free(rev);
    *dl = rlen;
    free(dist);
    free(parent);
    return ans;
}

int export_to_dot(const Graph *g, const char *filename) {
    if (!g || g->vertex_count == 0) {
        printf("Граф пуст, нечего экспортировать.\n");
        return -1;
    }
    FILE *f = fopen(filename, "w");
    if (!f) {
        perror("Ошибка открытия файла.");
        return -1;
    }
    fprintf(f, "digraph G {\n");
    for (int i = 0; i < g->vertex_count; i++) {
        fprintf(f, "    \"%s\";\n", g->vertices[i].name_cur);
    }
    for (int i = 0; i < g->vertex_count; i++) {
        Edge *e = g->vertices[i].edges;
        while (e) {
            fprintf(f, "    \"%s\" -> \"%s\" [label=\"%d\"];\n",
                    g->vertices[i].name_cur, e->name_to, e->lvl);
            e = e->next;
        }
    }
    fprintf(f, "}\n");
    fclose(f);
    return 0;
}
int find_idx(const Graph *g, const char *name) {
    for (int i = 0; i < g->vertex_count; ++i)
        if (strcmp(g->vertices[i].name_cur, name) == 0) return i;
    return -1;
}
char *floyd(const Graph *g, const char *name){
	int **dist = calloc(g->vertex_count, sizeof(int *));
	for(int i = 0; i<g->vertex_count; i++){
		dist[i] = calloc(g->vertex_count, sizeof(int));
	}
	for(int i = 0; i<g->vertex_count; i++){
		for(int j = 0; j<g->vertex_count; j++){
			if(i!=j){
				dist[i][j] = INT_MIN;
				continue;
			}
		}
	}
	for(int i = 0; i<g->vertex_count; i++){
		Edge *temp = g->vertices[i].edges;
		while(temp){
			dist[i][find_idx(g, temp->name_to)] = temp->lvl;
			temp = temp->next;
		}
	}
	for(int k = 0; k<g->vertex_count; k++){
		for(int i = 0; i<g->vertex_count; i++){
			if (dist[i][k] == INT_MIN) continue;
			for(int j = 0; j<g->vertex_count; j++){
				if (dist[k][j] == INT_MIN) continue;
				if(dist[i][k]+dist[k][j]>dist[i][j]){
					dist[i][j] = dist[i][k]+dist[k][j];
				}
			}
		}
	}
	int min = INT_MIN;
	char *ans = NULL;
	for(int i = 0; i<g->vertex_count; i++){
		if(dist[find_idx(g, name)][i]>min&&find_idx(g, name)!=i){
			min = dist[find_idx(g,name)][i];
			if(ans){
				free(ans);
			}
			ans = strdup(g->vertices[i].name_cur);
		}
	}
	for(int i = 0; i<g->vertex_count; i++){
		free(dist[i]);
	}
	free(dist);
	return ans;
}

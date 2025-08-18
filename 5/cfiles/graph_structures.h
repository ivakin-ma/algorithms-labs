#ifndef GRAPH_STRUCTURES_H
#define GRAPH_STRUCTURES_H
typedef struct Vertex {
    char *name_cur;
    struct Edge *edges;
} Vertex;
typedef struct Edge{
	char *name_to;
	int lvl;
	struct Edge *next;
} Edge;
typedef struct Graph {
    int vertex_count;
    Vertex *vertices;
} Graph;

#endif

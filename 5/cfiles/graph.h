#ifndef GRAPH_H
#define GRAPH_H
#include "graph_structures.h"
#include"inputout.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
void add_ver(Graph *, const char *);
void add_edg(Graph *, const char *, const char *, const int lvl);
void del_ver(Graph *, const char *);
void del_edg(Graph *, const char *, const char *);
void change_name(Graph *, const char *, const char *);
void change_lvl(Graph *, const char *, const char *, int);
void print_graph(const Graph *);
void free_graph(Graph *);
char **dfs(const Graph *, const char *, int, int *);
char **bellman_ford(const Graph *, const char *, const char *, int *, int *);
int export_to_dot(const Graph *, const char *);
char *floyd(const Graph *, const char *);
#endif

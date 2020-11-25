
#include <iostream>
#include <string>
#include <math.h>
#include <cstring>

#pragma once

struct edge_entry {
	int weight;
	struct node_entry* pointer;
	struct edge_entry* next;

};


struct node_entry {
	int node_position;
	struct edge_entry* edge_list;

};


struct min_heap {
	struct node_entry* previous_node;
	struct node_entry* current_node;
	int weight;

	struct min_heap* left;
	struct min_heap* right;

};

void print_list(node_entry** nodes, int max_edges);
void print_array(min_heap* array, int m);

class main
{
};

/*
typedef struct edge_entry {
	int weight;
	struct node_entry* pointer;
	struct edge_entry* next;

} edge_list;


typedef struct node_entry {
	int node_position;
	struct edge_entry* edge_list;

} node_table;


typedef struct min_heap {
	struct node_entry* previous_node;
	struct node_entry* current_node;
	int weight;

	struct min_heap* left;
	struct min_heap* right;

} min_heap;
*/
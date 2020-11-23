#pragma once

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

void build_min_heap(min_heap* edges, int size);
void min_heapify(min_heap* edges, int i, int n);
int minimum(min_heap* edges);

int extract_min(int Arr[]);
void decrease_key(int Arr[], int x, int k);
void insert(int Arr[], int x);

class heap
{
};

//void do_this(int);
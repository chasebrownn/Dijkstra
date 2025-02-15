﻿#include "util.h"
#include "main.h"
#include "heap.h"

#include <iostream>
#include <string>
#include <math.h>
#include <cstring>

using namespace std;

/* 
	As you know, Dijkstra’s algorithm solves the single-source shortest-paths problem on a weighted, directed
	graph G = (V, E) for the case in which all edge weights are non-negative. Therefore, we assume w(u, v) ≥ 0
	for each directed edge (u, v) ∈ E.

	Dijkstra’s algorithm maintains a set S of vertices whose final shortest-path weights from the source s
	have already been determined. The algorithm repeatedly selects the vertex u ∈ V − S with the minimum
	shortest-path estimate, adds u to S, and relaxes all edges leaving u.
	You are to implement Dijkstra’s algorithm using the psuedocode that follows, using a min-priority queue
	Q of vertices keyed by their distance values, and an adjacency list representation for G. The functions
	Initialize-Single-Source and Relax were provided and discussed in class.

	Initialize-Single-Source(G, s) {Initialize distance and predecessor of each vertex v ∈ V }
	S = ∅ {S is initially empty because no shortest-paths are determined yet}
	Q = V {Use Insert(Q, v) to insert each vertex v ∈ V into the min-priority queue Q}
	while ( Q != ∅ ) do
		u = Extract-Min(Q) {Extract the vertex u with current minimum distance from Q}
		S = S ∪ {u} {Add u into the set S of vertices whose final shortest-path has been determined}
		for each vertex v adjacent to u do
			Relax(u, v, w) {If the distance to v decreases to d 0, then Decrease-Key(Q, v, d0 )}
		end for
	end while
*/

/*
int dijkstra(min_heap* heap, node_entry** adjacency_list, int s, int size)
{
	min_dist* S = new min_dist;

	initialize_single_source(adjacency_list, S, s, size);

	// S = ∅
	// Q = V
	while () //Q != ∅
	{
		min_heap u = extract_min(heap);

	}

	return 0;
}


void initialize_single_source(node_entry** adjacency_list, min_dist* vertices, int s, int size) // G, s
{
	// for each of the vertex v in V[G] do ( d[v] = infinity pi[v] = NIL ) d[s] = 0
	// s needs to be the index of the node in the node table

	for (int i = 0; i < size; i ++)
	{
		vertices[i].current = NULL;
		vertices[i].previous = NULL;
		vertices[i].distance = ((10)^99);
	}

	vertices[s].distance = 0;

	// path[0].current = //source;
	
}

void relax(node_entry** adjacency_list, min_dist* vertices, int u, int v, int w) // u, v, w
{
	// if the distance of d[v] > d[u] + w(u, v)
			// then d[v] = d[u] + w(u, v)
				// prev[v] = u

	int weight = get_weight(adjacency_list, u, v, w);

	if (vertices[v].distance > vertices[u].distance + weight)
	{
		vertices[v].distance = vertices[u].distance + weight;
		vertices[v].previous = vertices[u];
	}
}


int get_weight(node_entry** adjacency_list, int u, int v, int w)
{
	edge_entry* pointer = (adjacency_list[u]->edge_list);

	while (pointer->next != NULL)
	{
		if (pointer->pointer->node_position == v)
		{
			return pointer->weight;
		}
		else
		{
			pointer = pointer->next;
		}
	}

	cout << "There is no edge from u to v" << endl;
	return 0;
}*/
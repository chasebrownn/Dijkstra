#include "main.h"
#include "heap.h"
#include "graph.h"
#include "util.h"

#include <iostream>
#include <string>
#include <math.h>
#include <cstring>

using namespace std;

/*
	First, your program is to read in a graph from stdin and construct its adjacency list representation. Recall
	that the adjacency list representation of a graph is an array (indexed by vertex), where the list for vertex v
	corresponds to a singly linked list of outgoing neighbours of v (the list of neighbours need not be ordered;
	you should be able to repurpose some of the you code for the hash table in Project 2).

	The first line of input contains two integers n and m, which correspond to the
	number of vertices and the number of edges of the graph, respectively.

	This line is followed by m lines, where
	each line contains three integers: u, v, and w. These three integers indicate the information associated with
	an edge, i.e., that there is a directed edge from u to v with weight w. Note that the vertices of the graph
	are indexed from 1 to n (and not from 0 to n − 1).
*/

typedef struct edge_entry {
	int weight;
	Node* pointer;

} Edge;

typedef struct node_entry {
	linkedlist* edge_list;

} Node;

typedef struct linkedlist_entry {
	Edge* data;	
	linkedlist* next;

} linkedlist;

int main(int argc, char** args) //int argc, char** args
{
	string num_of_vertices, num_of_edges;
	int n, m;

	cin >> num_of_vertices; // Take n number of vertices	
	n = stoi(num_of_vertices);

	cin >> num_of_edges; // Take m number of edges
	m = stoi(num_of_edges);

	//cout << n << " " << m << endl;

	Node* vertices = new Node[n];



	delete vertices;
}

void insert_edge()

/*void insert_hash(int position, hash_table** hash, char* app_name, tree* app_node) // Inserts app into the hash table
{
	hash_table* temp = (hash[position]);

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	hash_table* newEntry = new hash_table();

	strcpy(newEntry->app_name, app_name);
	newEntry->app_node = app_node;
	newEntry->next = NULL;
	if (temp->app_node != NULL)
	{
		hash[position]->next = newEntry;
	}
	else
	{
		hash[position] = newEntry;
	}

	//delete[] newEntry;
}*/
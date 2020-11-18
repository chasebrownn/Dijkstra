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
	struct node_entry* pointer;
	struct edge_entry* next;

} Edge;

typedef struct node_entry {
	struct linkedlist_entry* edge_list;

} Node;

typedef struct linkedlist_entry {
	struct edge_entry* data;
	struct linkedlist_entry* next;

} Linkedlist;

void insert_edges(Linkedlist*, int);
void print_list(Linkedlist*, int);

int main(int argc, char** args) //int argc, char** args
{
	string num_of_vertices, num_of_edges;
	int n, m;

	cin >> num_of_vertices; // Take n number of vertices	
	n = stoi(num_of_vertices);

	cin >> num_of_edges; // Take m number of edges
	m = stoi(num_of_edges);

	cout << n << " " << m << endl;

	//Node* vertices = new Node[n];

	Linkedlist* edges = new Linkedlist;
	Linkedlist* temp = edges;

	for (int i = 0; i < m; i++)
	{
		if (temp == NULL)
		{
			temp = new Linkedlist;
		}
		temp->data = NULL;
		temp = temp->next;
	}

	insert_edges(edges, m);
	//cout << "Seg Fault?" << endl;
	print_list(edges, m);


	//delete[] vertices;
	//delete[] edges;
}

void insert_edges(Linkedlist* edges, int max_edges)
{
	string u_str, v_str, w_str;
	int u, v, w;

	for (int i = 0; i < max_edges; i++)
	{
		cin >> u_str;
		cin >> v_str;
		cin >> w_str;
		cin.ignore(100, '\n');

		u = stoi(u_str); // 6
		v = stoi(v_str); // 11
		w = stoi(w_str);

		cout << u << " " << v << " " << w << " " << endl;

		Linkedlist* u_pointer = edges;
		Linkedlist* v_pointer = edges;
		
		for (int j = 1; j < u; j++)
		{
			if (u_pointer == NULL)
			{
				u_pointer = new Linkedlist;
			}
			u_pointer = u_pointer->next;
		}
		for (int x = 1; x < v; x++)
		{
			if (v_pointer == NULL)
			{
				v_pointer = new Linkedlist;
			}
			v_pointer = v_pointer->next;
		}

		cout << "Here?" << endl; // Does not reach here after pass 1

		Edge* data_pointer = u_pointer->data;

		if (data_pointer == NULL)
		{
			cout << "If-statement" << endl;
			data_pointer = new Edge();
			data_pointer->pointer = new Node();
			data_pointer->pointer->edge_list = v_pointer;
			data_pointer->weight = w;
		}
		else
		{
			cout << "While-loop" << endl;
			while (data_pointer != NULL)
			{
				data_pointer = data_pointer->next;
			}
			data_pointer = new Edge();
			data_pointer->pointer = new Node();
			data_pointer->pointer->edge_list = v_pointer;
			data_pointer->weight = w;
		}

		//delete[] temp_pointer;
		//delete[] v_pointer;
		//delete[] data_pointer;
		
	}
	
}

void print_list(Linkedlist* edges, int max_edges)
{
	Linkedlist* node_ptr = edges;
	int node = 1;

	while (node_ptr->next != NULL)
	{
		cout << "(u) Node: " << node << endl;

		Edge* data_ptr = node_ptr->data;

		while (data_ptr->next != NULL)
		{
			cout << "\t" << "(w) Weight: " << data_ptr->weight << endl;
			// Print v

			data_ptr->next;
		}

		node++;
		node_ptr->next;
	}
}

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
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

} edge_list;


typedef struct node_entry {
	struct edge_entry* edge_list;

} node_table;

/*
typedef struct linkedlist_entry {
	struct edge_entry* data;
	struct linkedlist_entry* next;

} Linkedlist;*/


void get_edges(node_table**, int);
void insert_edge(node_table** nodes, int u, int v, int w);
void print_list(node_table** nodes, int max_edges);


int main(int argc, char** args) //int argc, char** args
{
	string num_of_vertices, num_of_edges;
	int n, m;

	cin >> num_of_vertices; // Take n number of vertices	
	n = stoi(num_of_vertices);

	cin >> num_of_edges; // Take m number of edges
	m = stoi(num_of_edges);

	cout << n << " " << m << endl;

	node_table** vertices = new node_table*[n+1];

	for (int i = 0; i <= n; i++)
	{
		vertices[i] = new node_table();
		vertices[i]->edge_list = NULL;
	}

	/*
	Linkedlist* edges = new Linkedlist;
	edges->next = NULL;
	edges->data = NULL;
	Linkedlist* previous = edges;
	Linkedlist* temp = previous->next;

	for (int i = 1; i < m; i++)
	{
		if (temp == NULL)
		{
			temp = new Linkedlist;
			temp->next = NULL;
		}
		temp->data = NULL;
		previous->next = temp;
		previous = previous->next;
		temp = temp->next;
	}*/

	get_edges(vertices, m);
	print_list(vertices, n);



	//delete[] vertices;
	//delete[] edges;
}

void get_edges(node_table** nodes, int max_edges)
{
	string u_str, v_str, w_str;
	int u, v, w;

	for (int i = 0; i < max_edges; i++)
	{
		cin >> u_str;
		cin >> v_str;
		cin >> w_str;
		cin.ignore(100, '\n');

		u = stoi(u_str); 
		v = stoi(v_str); 
		w = stoi(w_str);

		cout << u << " " << v << " " << w << endl;

		insert_edge(nodes, u, v, w);
		

		/*Linkedlist* u_pointer = edges;
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

		Edge* data_pointer = u_pointer->data;

		if (data_pointer == NULL)
		{
			//cout << "If-statement" << endl;
			data_pointer = new Edge();
			data_pointer->pointer = new Node();
			data_pointer->pointer->edge_list = v_pointer;
			data_pointer->weight = w;
		}
		else
		{
			//cout << "While-loop" << endl;
			while (data_pointer != NULL)
			{
				data_pointer = data_pointer->next;
			}
			data_pointer = new Edge();
			data_pointer->pointer = new Node();
			data_pointer->pointer->edge_list = v_pointer;
			data_pointer->weight = w;
		}*/

		//delete[] temp_pointer;
		//delete[] v_pointer;
		//delete[] data_pointer;
		
	}
	
}

void insert_edge(node_table** nodes, int u, int v, int w)
{
	node_table* u_pointer = (nodes[u]);
	node_table* v_pointer = (nodes[v]);
	edge_list* edge_pointer = u_pointer->edge_list;

	if (edge_pointer == NULL)
	{		
		edge_list* new_entry = new edge_list();

		u_pointer->edge_list = new_entry;
		new_entry->pointer = v_pointer;
		new_entry->weight = w;
		new_entry->next = NULL;

		return;
	}
	else
	{
		while (edge_pointer->next != NULL)
		{
			edge_pointer = edge_pointer->next;
		}

		edge_list* new_entry = new edge_list();

		edge_pointer->next = new_entry;
		new_entry->pointer = v_pointer;
		new_entry->weight = w;
		new_entry->next = NULL;
	}
		
}


void print_list(node_table** nodes, int max_edges)
{
	for (int i = 1; i <= 25; i++)
	{
		edge_list* temp = (nodes[i]->edge_list);

		while (temp != NULL)
		{
			if (temp != NULL)
			{
				cout << "Weight of node[" << i << "]'s edge is: " << temp->weight << endl;
				//temp = temp->next;
			}
			temp = temp->next;
		}
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
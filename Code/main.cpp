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

void get_edges(node_entry**, int);
void insert_edge(node_entry** nodes, int u, int v, int w);
void create_array(node_entry** nodes, min_heap* array, int m, int n);
void get_commands();
void print_list(node_entry** nodes, int max_edges);
void print_array(min_heap* array, int m);


int main(int argc, char** args) //int argc, char** args
{
	string num_of_vertices, num_of_edges;
	int n, m;

	cin >> num_of_vertices; // Take n number of vertices	
	n = stoi(num_of_vertices);

	cin >> num_of_edges; // Take m number of edges
	m = stoi(num_of_edges);

	cout << n << " " << m << endl;

	int size = n + 1;

	//node_table** vertices = new node_table*[size];
	node_entry** vertices = new node_entry * [size];

	min_heap* array = new min_heap[m];

	for (int i = 0; i <= n; i++) // type mismatch
	{
		vertices[i] = new node_entry();
		vertices[i]->edge_list = NULL;
		vertices[i]->node_position = 0;
	}

	for (int i = 0; i < m; i++)
	{
		array[i].previous_node = NULL;
		array[i].current_node = NULL;		
		array[i].weight = 0;
		array[i].left = NULL;
		array[i].right = NULL;
	}

	get_edges(vertices, m);
	create_array(vertices, array, m, n);
	//print_list(vertices, n);
	print_array(array,m);
	build_min_heap(array, m);
	print_array(array, m);
	get_commands();

	//Stop, write, find

	//delete[] vertices;
	//delete[] edges;
}

void get_edges(node_entry** nodes, int max_edges)
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
	}
	
}

void insert_edge(node_entry** nodes, int u, int v, int w)
{
	node_entry* u_pointer = (nodes[u]);
	node_entry* v_pointer = (nodes[v]);
	edge_entry* edge_pointer = u_pointer->edge_list;

	if (edge_pointer == NULL)
	{		
		edge_entry* new_entry = new edge_entry();

		u_pointer->node_position = u;				
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

		edge_entry* new_entry = new edge_entry();

		edge_pointer->next = new_entry;
		new_entry->pointer = v_pointer;
		new_entry->weight = w;
		new_entry->next = NULL;
	}
		
}

void create_array(node_entry** nodes, min_heap* array, int m, int n) // m = edges n = nodes
{
	for (int i = 1, j = 0; i <= n; i++)
	{
		node_entry* prev_pointer = (nodes[i]);
		edge_entry* current_pointer = (nodes[i]->edge_list);

		while (current_pointer != NULL)
		{
			array[j].previous_node = prev_pointer;
			array[j].current_node = current_pointer->pointer;
			array[j].weight = current_pointer->weight;
			
			j++;
			current_pointer = current_pointer->next;
		}
	}
}

void get_commands()
{
	string line, s_str, t_str, flag_str;
	int s, t, flag;
	cin >> line;

	while (line != "stop")
	{
		if (line == "write")
		{
			/*  
				On reading write, your program must write the graph to stdout. The output format of the
				write command is as follows: The first line should contain two integers, n and m, where n is the
				number of vertices and m is the number of edges in the graph, respectively. This line must be followed
				by n lines, one for each vertex. If vertex u has k neighbours (u, vi) with weight wi, 1 ≤ i ≤ k, then for each vertex u, output:\

				u : (v1; w1); (v2; w2); . . . ; (vk; wk)
			*/

			cout << "Write..." << endl;
		}
		else if (line == "find")
		{
			/*
				find s t flag
				
				While your program reads in only one graph, it may be asked to compute s-t shortest paths for many
				different source-destination pairs s and t. Therefore, during the computation of the s-t shortest path, your
				program must not modify the given graph.
			*/

			cin >> s_str;
			cin >> t_str;
			cin >> flag_str;

			s = stoi(s_str);
			t = stoi(t_str);
			flag = stoi(flag_str);

			if (flag == 1)
			{
				/*	
					your program runs Dijkstra’s shortest path algorithm to compute the shortest
					path from s to t, and prints out the length of this shortest path to stdout. The information output
					format is:
					LENGTH: l (where l is the shortest path length)
				*/
			}
			else if (flag == 0)
			{
				/*	
					your program runs Dijkstra’s shortest path algorithm to compute a shortest
					path from s to t, and prints the actual path (sequence of vertices) to stdout. The information output
					format is:
					PATH:s; v1; v2; . . . ; vk;t
					where the sequence of vertices listed corresponds to the shortest path (s, v1); (v1, v2). . .(vk, t) computed
					of length k.
				*/
			}
			else
			{
				cout << flag << " is not a valid flag" << endl;
			}
		}
		else
		{
			cout << line << " is not a valid command inquiry" << endl;
		}
		cin >> line;
	}

	return;
}


void print_list(node_entry** nodes, int max_edges)
{
	for (int i = 1; i <= max_edges; i++)
	{
		edge_entry* temp = (nodes[i]->edge_list);

		while (temp != NULL)
		{
			if (temp != NULL)
			{			
				cout << "Weight of node[" << i << "]'s edge is: " << temp->weight << endl;				
			}
			temp = temp->next;
		}
	}
}

void print_array(min_heap* array, int m)
{
	for (int i = 0; i < m; i++)
	{
		cout << "[" << array[i].previous_node->node_position << "] ----- " << array[i].weight << " -----> [" << array[i].current_node->node_position << "]" << endl;
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
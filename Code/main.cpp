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


//TEST 7 FAILED

int main(int argc, char** args) //int argc, char** args
{
	string num_of_vertices, num_of_edges;
	int n, m;

	cin >> num_of_vertices; // Take n number of vertices
	n = stoi(num_of_vertices);

	cin >> num_of_edges; // Take m number of edges
	m = stoi(num_of_edges);

	//cout << n << " " << m << endl;

	int size = n + 1;
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
	//cout << endl;
	print_array(array, m);
	
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

			cout << "COMMAND: W" << endl;

			if (n == 0)
			{
				cout << "Error: graph not initialized" << endl;
			}
			else
			{
				print_list(vertices, n);
			}			
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

				cout << "COMMAND: F " << s << " " << t << " " << flag << endl;

				if (n == 0)
				{
					cout << "Error: invalid flag value" << endl;
				}
				else if (s <= 0 || s > n || t <= 0 || t > n)
				{
					cout << "Error: one or more invalid nodes" << endl;
				}
				else
				{					
					if (s - t == 0)
					{
						cout << "LENGTH: 0" << endl;
					}
					else
					{
						//dijkstra();

						cout << "LENGTH: " << endl;

					}					
				}				
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

				cout << "COMMAND: F " << s << " " << t << " " << flag << endl;

				if (n == 0)
				{
					cout << "Error: graph not initialized" << endl;
				}
				else if (s <= 0 || s > n || t <= 0 || t > n)
				{
					cout << "Error: one or more invalid nodes" << endl;
				}
				else
				{
					if (s - t == 0)
					{
						cout << "PATH: " << s << endl;
					}
					else
					{
						//dijkstra();

						cout << "PATH: " << endl;

					}
				}
			}
			else
			{
				cout << "COMMAND: F " << s << " " << t << " " << flag << endl;
				if (s <= 0 || s > n || t <= 0 || t > n)
				{
					cout << "Error: one or more invalid nodes" << endl;
				}
				cout << "Error: invalid flag value" << endl;
			}
		}
		else
		{
			cout << line << " is not a valid command inquiry" << endl;
		}
		cin >> line;
	}

	cout << "COMMAND: S" << endl;

	delete[] vertices;
	delete[] array;
}



/*
1 : (11, 1); (2, 7); (6, 2); (1, 3)
2 : (9, 3); (8, 1); (7, 10)
3 : (1, 5)
4 : (10, 10); (3, 4)
5 : (4, 7)
6 : (11, 3)
7 : (13, 3); (2, 10); (1, 4)
8 : (9, 1); (13, 2)
9 : (9, 4)
10 : (15, 7); (15, 6); (5, 3)
11 : (12, 4); (6, 2)
12 : (8, 2); (18, 8)
13 : (18, 1)
14 : (25, 30); (20, 16); (19, 1); (4, 15)
15 : (14, 2); (10, 8)
16 : (12, 7)
17 : (16, 13)
18 : (12, 7); (22, 3); (21, 1)
19 : (24, 1)
20 : (25, 15)
21 : (22, 1); (16, 4)
22 : (23, 5); (21, 2)
23 : (25, 8); (14, 1); (24, 4); (23, 7)
24 : (25, 26); (13, 9)
25 : (15, 2)
*/

void print_list(node_entry** nodes, int max_edges)
{
	for (int i = 1; i <= max_edges; i++)
	{
		edge_entry* temp = (nodes[i]->edge_list);
		node_entry* node = (nodes[i]);
		
		cout << node->node_position << " : ";

		while (temp != NULL)
		{
			if (temp != NULL)
			{			
				//cout << "Weight of node[" << i << "]'s edge is: " << temp->weight << endl;
				cout << "(" << temp->pointer->node_position << ", " << temp->weight << ")";
			}
			if (temp->next != NULL)
			{
				cout << "; ";
			}
			temp = temp->next;			
		}

		cout << endl;
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
#include "graph.h"

#include <iostream>
#include <string>
#include <math.h>
#include <cstring>

using namespace std;

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

		//cout << u << " " << v << " " << w << endl;

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
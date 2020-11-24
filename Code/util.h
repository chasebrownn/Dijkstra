#include "main.h"

#include <iostream>
#include <string>
#include <math.h>
#include <cstring>

#pragma once

struct min_dist {
	struct node_table* current;
	struct node_table* previous;
	int distance;

};

void initialize_single_source(min_dist* vertices, int s, int size);
void relax(int u, int v, int w);
int get_weight(node_entry** adjacency_list, int u, int v, int w);

class util
{
};


#include "main.h"

#include <iostream>
#include <string>
#include <math.h>
#include <cstring>

#pragma once


void build_min_heap(min_heap* edges, int size);
void min_heapify(min_heap* edges, int i, int n);
min_heap minimum(min_heap* edges);
min_heap extract_min(min_heap* edges);

void decrease_key(min_heap* edges, int x, int k);
void insert(min_heap* edges, int x);

class heap
{
};
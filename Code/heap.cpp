#include "heap.h"
#include <iostream>
#include <string>
#include <math.h>
#include <cstring>

using namespace std;

/*
void do_this(int n)
{
	cout << n << endl;
}*/

/*
	A priority queue is a data structure for maintaining a set S of elements, each with an associated value called
	a key. Priority queues come in two forms: Max-priority queues and min-priority queues. Our focus is on a
	min-priority queue because Dijkstra’s algorithm finds the shortest path to each vertex from a source, i.e., it
	works to minimize the path length.

	A min-priority queue supports four operations:

	1. Insert(S, x): Inserts the element x into the set S, which is equivalent to the operation S = S ∪ {x}.
	2. Minimum(S): Returns the element of S with the smallest key.
	3. Extract-Min(S): Removes and returns the element of S with the smallest key.
	4. Decrease-Key(S, x, k): Decreases the value of element x’s key to a new value k, where k is less than
	or equal to x’s current key value
*/

/*
void min_heapify(int Arr[], int i, int n)
{
	int left = 2 * 1;
	int right = 2 * i + 1;
	int smallest;

	if (left <= n && Arr[left] < Arr[i])
	{
		smallest = left;
	}
	else
	{
		smallest = i;
	}
	if (right <= n && Arr[right] < Arr[smallest])
	{
		smallest = right;
	}
	if (smallest != i)
	{
		swap(Arr[i], Arr[smallest]);
		min_heapify(Arr, smallest, n);
	}
}


int minimum(int Arr[])
{
	return Arr[1]; // Return the minimum element is the root element in the min heap
}

int extract_min(int Arr[])
{
	int length = sizeof(Arr);
	int min = Arr[1];
	Arr[1] = Arr[length];
	length = length - 1;
	min_heapify(Arr, 1);
	return min;
}

void decrease_key(int Arr[], int x, int k)
{
	if (k > Arr[x])
	{
		cout << "New value is greater than current value, can't be inserted" << endl;
		return;
	}
	Arr[x] = k;
	while (x > 1 && Arr[x/2] > Arr[x])
	{
		swap(Arr[x/2], Arr[x]);
		x = x / 2;
	}
}

void insert(int Arr[], int x)
{
	int length = sizeof(Arr);
	length = length + 1;
	Arr[length] = -1;
	decrease_key(Arr, length, x);
}*/
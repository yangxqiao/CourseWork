#ifndef HSORT_H
#define HSORT_H
#include <vector>

template <typename T, typename Comparator >
void hsort(std::vector<T>& data, Comparator c = Comparator());

// heapify() helper function
// loc - Location to start the heapify() process
// effsize - Effective size (number of items in the vector that
//           are part of the heap). Useful for performing heap-sort in place.
template <typename T, typename Comparator >
void heapify(std::vector<T>& data, size_t loc, size_t effsize, Comparator& c );


template <typename T, typename Comparator >
void hsort(std::vector<T>& data, Comparator c)
{
	// first sort the vector to be a heap
	int size_of_non_leaf_node = data.size()/2;
	for(int i = size_of_non_leaf_node-1; i >= 0; i--)
	{
		heapify(data, i, data.size(), c);
	}

	int effsize = data.size();
	for(int i = effsize-1; i >= 0; i--)
	{
		std::swap(data[0], data[i]);
		effsize = effsize-1;
		heapify(data, 0, effsize, c);
	}

	int size = data.size();
	for(int i = 0; i < size/2; i++)
	{
		std::swap(data[i], data[size-i-1]);
	}
}


// heapify() helper function
// loc - Location to start the heapify() process
// effsize - Effective size (number of items in the vector that
//           are part of the heap). Useful for performing heap-sort in place.
template <typename T, typename Comparator >
void heapify(std::vector<T>& data, size_t loc, size_t effsize, Comparator& c )
{
	if(loc >= effsize/2)
	{
		return;
	}
	unsigned int better_child = (loc+1)*2-1;
	if(better_child+1 < effsize)
	{
		unsigned int rchild = better_child+1;
		if(c(data[rchild], data[better_child]))
		{
			better_child = rchild;
		}
	}
	if(c(data[better_child], data[loc]))
	{
		std::swap(data[better_child], data[loc]);
		heapify(data, better_child, effsize, c);
	}
}

#endif
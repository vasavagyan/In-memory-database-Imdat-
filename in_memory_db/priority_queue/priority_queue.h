#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "../string/string.h"

#include <vector>

class MaxHeap
{
public:
	MaxHeap() : heap(1) {};
	const String& top() const { return (heap[1].data); }
	void push(const String&, int);
	String pop();
	void clear() { heap.clear(); }
	unsigned int get_size() { return (heap.size()); }

private:
	struct Node
	{
		Node() = default;
		Node(const String& str, unsigned int prior) : data{str} { priority = prior; }
		
		unsigned int priority = 0;
		String data;
	};
	std::vector<Node> heap;
};

#endif //PRIORITY_QUEUE_H

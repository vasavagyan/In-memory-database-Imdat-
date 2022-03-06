#include "priority_queue.h"
#include "../string/string.h"

#include <iostream>

void MaxHeap::push(const String& data, int priority)
{
	heap.push_back(Node(data, priority));
	unsigned int curr_index;

	curr_index = heap.size() - 1;
	while (heap[curr_index].priority > heap[curr_index / 2].priority && curr_index != 1) {
		std::swap (heap[curr_index], heap[curr_index / 2]);
		curr_index /= 2;
	}
	while (heap[curr_index].priority == heap[curr_index / 2].priority && curr_index != 1) {
		if (heap[curr_index].data > heap[curr_index / 2].data) {
			std::swap(heap[curr_index], heap[curr_index / 2]);
			curr_index /= 2;
		} else {
			break;
		}
	}
}

String MaxHeap::pop()
{   
	String temporary = heap[1].data;
	if (1 == heap.size() - 1) {
		heap.pop_back();
		return temporary;
	}

	std::swap(heap[1], heap[heap.size() - 1]);
	heap.pop_back();
	int i = 1;

	while (i * 2 < heap.size() && heap[i].priority < heap[i * 2].priority || i * 2 + 1 < heap.size()  && heap[i].priority < heap[i * 2 + 1].priority) {
		if (i * 2 + 1 >= heap.size() || heap[i * 2].priority < heap[i * 2 + 1].priority) { 
			std::swap (heap[i], heap[i * 2]);
			i *= 2;
		} else {
			std::swap(heap[i], heap[i * 2 + 1]);
			i *= 2;
			++i;
		}
	}
	return (temporary);
}

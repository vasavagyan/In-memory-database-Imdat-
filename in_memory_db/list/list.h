#ifndef LIST_H
#define LIST_H

#include <iostream>

template <typename T>
class List
{
private:
	template <typename U>
	struct Node
	{
		Node() = default;
		Node(const T& el, Node* n = nullptr, Node* p = nullptr) : val(el), next(n), prev(p) {}

		T val;
		Node* next{};
		Node* prev{};
	};

	Node<T>* head{};
	Node<T>* tail{};

public:
	class iterator: public std::iterator<std::bidirectional_iterator_tag, T>
        {
        public:
        	iterator(Node<T> * node = nullptr);
        	iterator(const iterator&);
        	iterator& operator=(const iterator&);
        	iterator(iterator&&) noexcept;
		iterator& operator=(iterator&&) noexcept;
		
		iterator& operator++();
		iterator operator++(int);
		iterator& operator--();
		iterator operator--(int);
		bool operator!=(const iterator& other) const;
		const T& operator*() const;
		T& operator*();
		T* operator->();
		friend iterator List<T>::insert(iterator, const T&);
		friend void List<T>::erase(iterator);
        private:
        	Node<T>* it;
	};

	List() = default;
	List(const List&);
	List& operator=(const List&);
	List(List&&) noexcept;
	List& operator=(List&&) noexcept;
	~List();

	void pop_back();
	void pop_front();
	T front() const { return *head; }
	T back() const { return *tail; }
	void clear();
	size_t size() const;

	iterator begin();
	iterator end();
	iterator insert(iterator,const T&);
	iterator push_back(const T&);
	iterator push_front(const T&);
	void erase(iterator);
};

#include "list.hpp"

#endif //LIST_H

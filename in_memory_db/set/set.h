#ifndef SET_H
#define SET_H

#include "../string/string.h"

class Set
{
public:
	Set() = default;
	Set(const Set&) = default;
	Set& operator=(const Set&) = default;
	~Set() { clear(); }

	void insert(const String&);
	void remove(const String&);
	void clear();
	bool empty() const;
	int height() const { return _height(root); }

	void inorder() const;
	void preorder() const;
	void postorder() const;
	String get() const;

private:
	struct Node
	{
		Node() = default;
		Node(String str, Node* l = nullptr, Node* r = nullptr) : data(str), left(l), right(r) {}

		String data;
		Node* left{};
		Node* right{};
	};

	Node* root{};

	int _height(Node*) const;
	int _difference(Node*) const;
	Node* _balance(Node*);
	Node* _remove(const String&, Node*);
	void _insert(const String&, Node*&);
	void _inorder(Node*) const;
	void _preorder(Node*) const;
	void _postorder(Node*) const;
	void _clear(Node*);
	void _get(String&, Node*) const;
	
	Node* _rotate_RR(Node*);
	Node* _rotate_LL(Node*);
	Node* _rotate_RL(Node*);
	Node* _rotate_LR(Node*);
};

#endif //SET_H

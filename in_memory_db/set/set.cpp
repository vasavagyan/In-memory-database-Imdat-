#include "set.h"
#include <algorithm>	//for std::max

int Set::_height(Node* curr) const
{
	if (!curr) {
		return 0;
	}
	
	return std::max(_height(curr->left), _height(curr->right)) + 1;

}

int Set::_difference(Node* curr) const
{
	return (_height(curr->left) - _height(curr->right));
}

Set::Node* Set::_rotate_RR(Node* curr)
{
	Node* tmp = curr->right;
	curr->right = tmp->left;
	tmp->left = curr;
	
	return tmp;
}

Set::Node* Set::_rotate_LL(Node* curr)
{
	Node* tmp = curr->left;
	curr->left = tmp->right;
	tmp->right = curr;

	return tmp;
}

Set::Node* Set::_rotate_RL(Node* curr)
{
	Node* tmp = curr->right;
	curr->right = _rotate_LL(tmp);

	return _rotate_RR(curr);
}

Set::Node* Set::_rotate_LR(Node* curr)
{
	Node* tmp = curr->left;
	curr->left = _rotate_RR(tmp);

	return _rotate_LL(curr);
}

Set::Node* Set::_balance(Node* curr)
{
	int balanceFactor = _difference(curr);

	if (balanceFactor > 1) {
		if (_difference(curr->left) > 0) {
			curr = _rotate_LL(curr);
		} else {
			curr = _rotate_LR(curr);
		}
	} else if (balanceFactor < -1) {
		if (_difference(curr->right) > 0) {
			curr = _rotate_RL(curr);
		} else {
			curr = _rotate_RR(curr);
		}
	}

	return curr;
}

void Set::insert(const String& str)
{
	return _insert(str, root);
}

void Set::_insert(const String& str, Node*& head)
{
	if (!head) {
		head = new Node(str);
		return;
	}

	if (str < head->data) {
		_insert(str, head->left);
		head = _balance(head);
	} else if (str >= head->data) {
		_insert(str, head->right);
		head = _balance(head);
	}
}

void Set::inorder() const
{
	_inorder(root);
}

void Set::_inorder(Node* head) const
{
	if (!head) {
		return;
	}
	_inorder(head->left);
	std::cout << head->data << std::endl;
	_inorder(head->right);
}

void Set::preorder() const
{
	_preorder(root);
}

void Set::_preorder(Node* head) const
{
	if (!head) {
		return;
	}
	std::cout << head->data << std::endl;
	_preorder(head->left);
	_preorder(head->right);
}

void Set::postorder() const
{
	_postorder(root);
}

void Set::_postorder(Node* head) const
{
	if (!head) {
		return;
	}
	_postorder(head->left);
	_postorder(head->right);
	std::cout << head->data << " ";
	std::cout << std::endl;
}

String Set::get() const
{
	String val;
	_get(val, root);
	return val;
}

void Set::_get(String& str, Node* head) const
{
	if (!head) {
		return;
	}
	_get(str, head->left);
	str = str + " " + head->data;
	_get(str, head->right);
}

void Set::remove(const String& str)
{
	root = _remove(str, root);
}

Set::Node* Set::_remove(const String& str, Node* head)
{
	if (!head) {
		return head;
	}

	if (head->left == nullptr && head->right == nullptr) {
		if (head == root) {
			root = nullptr;
		}
		delete head;
		head = nullptr;

		return head;
	}
	
	Node* q = nullptr;
	
	if (head->data < str) {
		head->right = _remove(str, head->right);
		head = _balance(head);
	} else if (head->data > str) {
		head->left = _remove(str, head->left);
		head = _balance(head);
	} else {
		if (head->left != nullptr) {
			Node* tmp = head->left;
			while (tmp->right) {
				tmp = tmp->right;
			}
			q = tmp;

			head->data = q->data;
			head->left = _remove(q->data, head->left);
			head = _balance(head);
		} else {
			Node* tmp = head->right;
			while (tmp->left) {
				tmp = tmp->left;
			}
			q = tmp;
			head->data = q->data;
			head->right = _remove(q->data, head->right);
			head = _balance(head);
		}
	}
	head = _balance(head);

	return head;
}

void Set::clear()
{
	_clear(root);
	root = nullptr;
}

void Set::_clear(Node* head)
{
	if (!head) {
		return;
	}
	_clear(head->left);
	_clear(head->right);
	delete head;
}

bool Set::empty() const
{
	if (root == nullptr) {
		return true;
	}
	return false;
}

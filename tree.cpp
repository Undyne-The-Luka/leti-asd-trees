#include "stdafx.h"
#include "tree.h"
#include <iostream>
#include <algorithm>
#include <queue>

void print_n_times(char char_to_print, int n);

Node::Node(char d, int dep) : data{d},depth{dep},left{nullptr},center{nullptr},right{nullptr}
{
}

int Node::height()
{
    int l_h = left ? left->height() : -1;
    int c_h = center ? center->height() : -1;
    int r_h = right ? right->height() : -1;
    return std::max(l_h,std::max(c_h,r_h)) + 1;
}

void Node::print()
{
    print_n_times(' ', (depth-1)*4);
    if (depth > 0) std::cout << "L___";
    std::cout << data << std::endl;
    if (!(left || center || right)) return;
    if (left) left->print(); else print_empty_child();
    if (center) center->print(); else print_empty_child();
    if (right) right->print();else print_empty_child();
}

void Node::print_empty_child()
{
    print_n_times(' ', (depth)*4);
    std::cout << "L___*" << std::endl;
}


Node::~Node()
{
}


Tree::Tree() : last_tag{'A'}, root{new Node{last_tag, 0}}, num_of_childs{0}
{
    add_child(root);
}

Tree::~Tree()
{
}


void Tree::add_child(Node* parent)
{
    int depth = parent->depth + 1;
    bool want_more = depth < rand() % 6;
    if (want_more) {
        parent->left = new Node{++last_tag, depth};
        add_child(parent->left);
    }

    want_more = depth < rand() % 6;
    if (want_more) {
        parent->center = new Node{++last_tag, depth};
        add_child(parent->center);
    }
    want_more = depth < rand() % 6;
    if (want_more) {
        parent->right = new Node{++last_tag, depth};
        add_child(parent->right);
    }

}

void Tree::print()
{
    if (root) root->print();
	std::cout << "\n";
}

void Tree::hight()
{
	int max_depth = 0;
	if (!root->center)
	{
		std::cout << "Central tree is not exist";
		return;
	}
	std::queue <Node*> Q;
	Q.push(root->center);
	while (Q.empty() == 0)
	{
		Node* current_node = Q.front();
		Q.pop();
		if (max_depth < current_node->depth)
			max_depth = current_node->depth;
		if (current_node->left) Q.push(current_node->left);
		if (current_node->center) Q.push(current_node->center);
		if (current_node->right) Q.push(current_node->right);
	}
	std::cout << "Central tree hight = " << max_depth - 1;
	std::cout << "\n";
}

void Tree::wide_walk()
{
	std::queue <Node*> Q;
	Q.push(root);
	while (Q.empty() == 0)
	{
		Node* current_node = Q.front();
		Q.pop();
		std::cout << current_node->data << " ";
		if (current_node->left) Q.push(current_node->left);
		if (current_node->center) Q.push(current_node->center);
		if (current_node->right) Q.push(current_node->right);
	}
	std::cout << "\n";
}

void print_n_times(char char_to_print, int n)
{
    for (int i = 0; i < n; i++) {
        std::cout << char_to_print;
    }
}


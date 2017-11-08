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
    delete left;
    delete center;
    delete right;
}


Tree::Tree(int depth_limit) : last_tag{'A'}, root{new Node{last_tag, 0}}, num_of_children{0}
{
    add_random_children_to_parent_until_depth_limit_reached(root, depth_limit);
}


Tree::~Tree()
{
    delete root;
}


void Tree::add_random_children_to_parent_until_depth_limit_reached(Node* parent, int depth_limit)
{
    int depth = parent->depth + 1;
    bool want_more = depth < rand() % depth_limit;
    if (want_more) {
        parent->left = new Node{++last_tag, depth};
        num_of_children++;
        add_random_children_to_parent_until_depth_limit_reached(parent->left, depth_limit);
    }

    want_more = depth < rand() % depth_limit;
    if (want_more) {
        parent->center = new Node{++last_tag, depth};
        num_of_children++;
        add_random_children_to_parent_until_depth_limit_reached(parent->center, depth_limit);
    }
    want_more = depth < rand() % depth_limit;
    if (want_more) {
        parent->right = new Node{++last_tag, depth};
        num_of_children++;
        add_random_children_to_parent_until_depth_limit_reached(parent->right, depth_limit);
    }

}

void Tree::print()
{
    if (root) root->print();
	std::cout << "\n";
}

void Tree::center_subtree_height()
{
	int max_depth = 0;
	if (!root || !root->center)
	{
		std::cout << "Central tree does not exist. Sorry.\n";
		return;
	}
	std::queue <Node*> nodes_queue;
	nodes_queue.push(root->center);
	while (!nodes_queue.empty())
	{
		Node* current_node = nodes_queue.front();
		nodes_queue.pop();
		if (max_depth < current_node->depth)
			max_depth = current_node->depth;
		if (current_node->left) nodes_queue.push(current_node->left);
		if (current_node->center) nodes_queue.push(current_node->center);
		if (current_node->right) nodes_queue.push(current_node->right);
	}
	std::cout << "Central tree hight: " << max_depth - 1;
	std::cout << "\n";
}

void Tree::wide_walk()
{
	std::queue <Node*> nodes_queue;
	nodes_queue.push(root);
	while (!nodes_queue.empty())
	{
		Node* current_node = nodes_queue.front();
		nodes_queue.pop();
		std::cout << current_node->data << " ";
		if (current_node->left) nodes_queue.push(current_node->left);
		if (current_node->center) nodes_queue.push(current_node->center);
		if (current_node->right) nodes_queue.push(current_node->right);
	}
	std::cout << "\n";
}

void print_n_times(char char_to_print, int n)
{
    for (int i = 0; i < n; i++) {
        std::cout << char_to_print;
    }
}


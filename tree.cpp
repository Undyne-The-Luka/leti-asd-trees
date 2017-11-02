#include "tree.h"
#include <iostream>
#include <algorithm>

void print_n_times(char n);

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
    }

    want_more = rand() % 6 + 1;
    if (want_more) {
        parent->center = new Node{++last_tag, depth};
    }
    want_more = rand() % 6 + 1;
    if (want_more) {
        parent->right = new Node{++last_tag, depth};
    }

}

void Tree::print()
{
    const int OUTPUT_WIDTH = 100;
    int current_output_width = 1;

    std::cout <<

    auto current_node = root;
    while (current_node) {
        auto left_node_data = current_node->left ? current_node->left->data : '\0';
        auto center_node_data = current_node->center ? current_node->center->data : '\0';
        auto right_node_data = current_node->right ? current_node->right->data : '\0';

        std::cout << "*" << left_node_data << "*" << center_node_data << "*" << right_node_data << std::endl;

    }
}

void Tree::stright_walk()
{
}

void Tree::wide_walk()
{
}



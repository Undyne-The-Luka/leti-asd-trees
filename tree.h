#ifndef TREE_H
#define TREE_H

#include <string>

class Node {
public:
    Node () = delete;
    Node (char d, int dep);
    ~Node ();
    char data;
    int depth;
    Node * left;
    Node * center;
    Node * right;

    int height();
    void print();
    void print_empty_child();
};

class Tree {
    char last_tag;
    Node * root;
    int num_of_children;

public:
    Tree () = delete;
    Tree (int, bool);
    Tree (const Tree&) = delete;
    Tree (Tree&&) = delete;
    Tree operator = (const Tree&) = delete;
    Tree operator = (Tree&&) = delete;
    ~Tree();

public:
    void add_random_children_to_parent_until_depth_limit_reached(Node* parent, int depth_limit);
    void add_children_if_requested(Node* parent, int depth_limit);

    void print();

    void center_subtree_height();
    void wide_walk();

    friend class Node;
};

#endif

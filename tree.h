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

public:
    Tree ();
    Tree (const std::string);
    Tree (const Tree&) = delete;
    Tree (Tree&&) = delete;
    Tree operator = (const Tree&) = delete;
    Tree operator = (Tree&&) = delete;
    ~Tree();

public:
    void add_random_childs_to(Node * parent);

    void print();

    void center_subtree_height();
    void wide_walk();

    friend class Node;
};

#endif

#ifndef TREE_H
#define TREE_H

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
};

class Tree {
    char last_tag;
    Node * root;
    int num_of_childs;

public:
    Tree ();
    Tree (const Tree&) = delete;
    Tree (Tree&&) = delete;
    Tree operator = (const Tree&) = delete;
    Tree operator = (Tree&&) = delete;
    ~Tree();

public:
    void add_child(Node * parent);
    void print();

    void stright_walk();
    void wide_walk();

    friend class Node;
};

#endif

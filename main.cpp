#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include "tree.h"

using namespace std;
int main() {
	srand(time(NULL));

    int max_tree_depth = 0;
    cout << "Input max tree depth: ";
    cin >> max_tree_depth;

    if (max_tree_depth <= 0 || max_tree_depth > 30) {
        throw out_of_range("Kuda stoko vershin!");
    }

	Tree random_tree{max_tree_depth};

	random_tree.print();
	random_tree.wide_walk();
    random_tree.center_subtree_height();


	//std::cout << "Goodbye, world!" << std::endl;
	return 0;
}

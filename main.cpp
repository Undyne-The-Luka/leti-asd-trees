#include <cstdlib>
#include <ctime>
#include "tree.h"

int main() {
	srand(time(NULL));

	Tree random_tree{};

	random_tree.print();
	random_tree.wide_walk();
    random_tree.center_subtree_height();


	//std::cout << "Goodbye, world!" << std::endl;
	return 0;
}

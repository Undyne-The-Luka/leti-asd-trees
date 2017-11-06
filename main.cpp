#include <iostream>
#include "tree.h"

int main() {
	srand(time(NULL));

	Tree tr{};

	tr.print();
	tr.wide_walk();
	tr.hight();


	std::cout << "Goodbye, world!" << std::endl;
	return 0;
}

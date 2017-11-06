#include <iostream>
#include "tree.h"

int main() {
    srand(time(NULL));

    Tree tr{};

    tr.print();
	std::cout << "\n";
    tr.wide_walk();
	std::cout << "\n";
	tr.hight();
	std::cout << "\n";


    std::cout << "Goodbye, world!" << std::endl;
    return 0;
}

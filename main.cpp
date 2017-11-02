#include <iostream>
#include "tree.h"

int main() {
    srand(time(NULL));

    Tree tr{};

    tr.print();
    tr.stright_walk();
    tr.wide_walk();


    std::cout << "Goodbye, world!" << std::endl;
    return 0;
}

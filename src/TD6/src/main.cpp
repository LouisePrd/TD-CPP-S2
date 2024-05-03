#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "node.hpp"

int main()
{
    Node *n = create_node(3);
    n->insert(6);
    n->insert(2);
    n->insert(4);
    n->insert(1);
    n->insert(5);
    n->insert(2);

    pretty_print_left_right(*n);
    std::cout << n->height() << std::endl;
    return 0;
}
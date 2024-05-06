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
    n->insert(6);
    n->insert(7);
    n->insert(8);

    // Height de l'arbre
    //std::cout << n->height() << std::endl;

    // Suppression des enfants
    /*n->delete_childs();
    pretty_print_left_right(*n);*/

    pretty_print_left_right(*n);

    return 0;
}
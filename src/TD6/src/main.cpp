#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "node.hpp"

int main()
{
    Node *n = create_node(5);
    for (int i : {3, 7, 1, 4, 6, 8, 2})
    {
        n->insert(i);
    }

   

    // Height de l'arbre
    // std::cout << n->height() << std::endl;

    // Suppression des enfants
    /*n->delete_childs();
    pretty_print_left_right(*n);*/

    pretty_print_left_right(*n);
    n->display_infixe();

    return 0;
}
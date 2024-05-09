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

    // Parcours de l'arbre
    //n->display_infixe();

    //pretty_print_left_right(*n);
    std::vector<Node const *> v = n->prefixe();
    for (Node const *n : v)
    {
        std::cout << n->value << " ";
    }

    return 0;
}
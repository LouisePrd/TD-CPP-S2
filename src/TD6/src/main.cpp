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

    // Hauteur de l'arbre
    // std::cout << n->height() << std::endl;

    // Suppression des enfants
    /*n->delete_childs();
    pretty_print_left_right(*n);*/

    // Parcours de l'arbre
    /*n->display_infixe();
    std::vector<Node const *> v = n->prefixe();
    for (Node const *n : v)
        std::cout << n->value << " ";*/

    // Remove d'un noeud
    /*pretty_print_left_right(*n);
    remove(n, 8);
    pretty_print_left_right(*n);*/



    return 0;
}
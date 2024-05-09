#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "node.hpp"

int main()
{
    // Exercice 1 (Implémentation)

    // Création de l'arbre
    /*Node *n = create_node(5);
    for (int i : {3, 7, 1, 4, 6, 8, 2})
    {
        n->insert(i);
    }*/

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

    // Suppression de l'arbre
    /*delete_tree(n);
    pretty_print_left_right(*n);*/

    // Exercice 2 (Utilisation)
    Node *n = create_node(5);
    for (int i : {3, 7, 2, 4, 6, 8, 1, 9, 0})
    {
        n->insert(i);
    }
    std::cout << "Arbre :" << std::endl;
    pretty_print_left_right(*n);
    std::cout << "Parcours infixe : ";
    n->display_infixe();
    std::cout << std::endl;

    std::vector<Node const *> v = n->prefixe();
    int sommeArbre = 0;
    for (Node const *n : v)
        sommeArbre+=n->value;
    std::cout << "Somme de toutes les valeurs de l'arbre : " << sommeArbre << std::endl;
    std::cout << "Hauteur de l'arbre : " << n->height() << std::endl;

    int maxTree = 0;
    maxTree = maxValue(n, maxTree);
    std::cout << "Valeur max de l'arbre : " << maxTree << std::endl;
    std::cout << "Valeur min de l'arbre : " << minValue(n, maxTree) << std::endl;
    return 0;
}
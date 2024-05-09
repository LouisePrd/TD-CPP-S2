#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "node.hpp"

void pretty_print_left_right(Node const &node, std::string const &prefix, bool is_left)
{
    if (node.right)
    {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left)
    {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const &node)
{
    pretty_print_left_right(node, "", true);
}

Node *create_node(int value)
{
    Node *newNode{new Node{value, nullptr, nullptr}};
    return newNode;
}

bool Node::is_leaf() const
{
    return (left == nullptr && right == nullptr);
}

void Node::insert(int value)
{
    if (value < this->value)
    {
        if (this->left == nullptr)
            left = create_node(value);
        // std::cout << "Inséré à gauche" << std::endl;
        else
            this->left->insert(value);
    }
    else
    {
        if (this->right == nullptr)
            right = create_node(value);
        // std::cout << "Inséré à droite" << std::endl;
        else
            this->right->insert(value);
    }
}

int Node::height() const
{
    int max = 0;
    if (this->left && this->right)
    {
        int left_height = this->left->height();
        int right_height = this->right->height();
        max = std::max(left_height, right_height) + 1;
    }
    else if (this->left)
    {
        max = this->left->height() + 1;
    }
    else if (this->right)
    {
        max = this->right->height() + 1;
    }
    else if (this->is_leaf())
    {
        max = 1;
    }

    return max;
}

void Node::delete_childs()
{
    if (this->left)
    {
        left->delete_childs();
        delete left;
        left = nullptr;
    }
    if (this->right)
    {
        right->delete_childs();
        delete right;
        right = nullptr;
    }
}

void Node::display_infixe() const
{
    if (this->left)
    {
        this->left->display_infixe();
        std::cout << this->value;
        if (this->right)
            this->right->display_infixe();
    }
    else if (this->right)
    {
        if (this->left)
            this->left->display_infixe();
        this->right->display_infixe();
        std::cout << this->value;
    }
    else if (this->is_leaf())
    {
        std::cout << this->value;
    }
}

std::vector<Node const *> result;
std::vector<Node const *> Node::prefixe() const
{
    if (this->left)
    {
        result.push_back(this);
        this->left->prefixe();
        if (this->right)
            this->right->prefixe();
    }
    else if (this->right)
    {
        result.push_back(this);
        this->right->prefixe();
        if (this->left)
            this->left->prefixe();
    }
    else if (this->is_leaf())
        result.push_back(this);

    return result;
}

Node *&most_left(Node *&node)
{
    if (node->left)
        return most_left(node->left);
    else if (node->right)
        return most_left(node->right);
    else
        return node;
}

// node est le noeuf racine
// int valeur à supp
bool remove(Node *&node, int value)
{
    if (value == node->value && node->is_leaf())
    {
        delete node;
        node = nullptr;
        return true;
    }
    else if (value == node->value && node->left && node->right == nullptr)
    {
        node = node->left;
        delete node->left;
        node->left = nullptr;
        return true;
    }
    else if (value == node->value && node->right && node->left == nullptr)
    {
        node = node->right;
        delete node->right;
        node->right = nullptr;
        return true;
    }
    else if (value == node->value && node->left && node->right)
    {
        Node *noeudGauche = most_left(node);
        std::cout << "Noeud le plus à gauche : " << noeudGauche->value << std::endl;
        node->value = noeudGauche->value;
        if (node->left)
            remove(node->left, noeudGauche->value);
        else if (node->right)
            remove(node->right, noeudGauche->value);
        return true;
    }
    else
    {
        if (value < node->value)
        {
            if (node->left)
                return remove(node->left, value);
        }
        else
        {
            if (node->right)
                return remove(node->right, value);
        }
    }
}

void delete_tree(Node *node)
{
    if (node->left)
        delete_tree(node->left);
    if (node->right)
        delete_tree(node->right);
    if (node->is_leaf())
    {
        delete node;
        node = nullptr;
    }
    else
    {
        delete node;
        node = nullptr;
    }
}

int maxValue(Node *node, int &max)
{
    if (node->left)
    {   if (node->value > max)
            max = node->value;
        maxValue(node->left, max);
    }
    if (node->right)
    {   if (node->value > max)
            max = node->value;
        maxValue(node->right, max);
    } else if (node->is_leaf())
    {
        if (node->value > max)
            max = node->value;
    }
    return max;
}

int minValue(Node *node, int &min)
{
    if (node->left)
    {   if (node->value < min)
            min = node->value;
        minValue(node->left, min);
    }
    if (node->right)
    {   if (node->value < min)
            min = node->value;
        minValue(node->right, min);
    } else if (node->is_leaf())
    {
        if (node->value < min)
            min = node->value;
    }
    return min;
}
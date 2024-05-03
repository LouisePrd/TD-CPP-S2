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
        if (this->left == nullptr){
        left = create_node(value);
        std::cout << "Inséré à gauche" << std::endl;
        } else {
            this->left->insert(value);
        }
    }
    else
    {
        if(this->right == nullptr){
        right = create_node(value);
        std::cout << "Inséré à droite" << std::endl;
        } else {
            this->right->insert(value);
        }
    }
}

int heightNode = 1;
int Node::height() const
{
    if (this->is_leaf())
    {
        return heightNode;
    }
    else
    {
        heightNode++;
        if (this->left)
        {
            this->left->height();
        }
        if (this->right)
        {
            this->right->height();
        }
    }

    return heightNode;
}
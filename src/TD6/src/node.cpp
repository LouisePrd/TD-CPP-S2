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
        left = create_node(value);
    else
        right = create_node(this->value);
}

int Node::height() const
{
    int heigh;
    while (left != nullptr)
    {
        heigh++;
    }
    return heigh;
}
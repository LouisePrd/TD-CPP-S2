#pragma once
#include <iostream>
#include <vector>

enum class TokenType
{
    OPERATOR,
    OPERAND
};

enum class Operator
{
    ADD,
    SUB,
    MUL,
    DIV,
    OPEN_PAREN,
    CLOSE_PAREN,
    PUISS
};


struct Token
{
    TokenType type;
    float value;
    Operator op;
};

std::string to_string(Operator op);
Token make_token(float value);
Token make_token(Operator op);
std::vector<Token> tokenize(std::vector<std::string> const &words);
bool is_floating(std::string const &s);
float npi_evaluate(std::vector<Token> const& tokens);
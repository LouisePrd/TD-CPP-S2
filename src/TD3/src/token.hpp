#pragma once
#include <iostream>

struct Token
{
    TokenType type;
    float value;
    Operator op;
};

enum class Operator
{
    ADD,
    SUB,
    MUL,
    DIV,
    OPEN_PAREN,
    CLOSE_PAREN
};

enum class TokenType
{
    OPERATOR,
    OPERAND
};

Token make_token(float value);
Token make_token(Operator op);

#include "token.hpp"
#include <iostream>
#include <vector>

bool is_floating(std::string const &s)
{
    for (char c : s)
    {
        if (!isdigit(c) && c != '.' && c != ',')
            return false;
    }
    return true;
}

Token make_token(float value)
{
    return Token{TokenType::OPERAND, value, Operator::ADD};
}

Token make_token(Operator op)
{
    return Token{TokenType::OPERATOR, 0, op};
}

std::vector<Token> tokenize(std::vector<std::string> const &words)
{
    std::vector<Token> tokens;
    for (unsigned int i = 0; i < words.size(); i++)
    {
        if (is_floating(words[i]))
        {
            tokens.push_back(make_token(std::stof(words[i])));
        }
        else
        {
            if (words[i] == "+")
            {
                tokens.push_back(make_token(Operator::ADD));
            }
            else if (words[i] == "-")
            {
                tokens.push_back(make_token(Operator::SUB));
            }
            else if (words[i] == "*")
            {
                tokens.push_back(make_token(Operator::MUL));
            }
            else if (words[i] == "/")
            {
                tokens.push_back(make_token(Operator::DIV));
            }
            else if (words[i] == "(")
            {
                tokens.push_back(make_token(Operator::OPEN_PAREN));
            }
            else if (words[i] == ")")
            {
                tokens.push_back(make_token(Operator::CLOSE_PAREN));
            }
        }
    }
    return tokens;
}

float npi_evaluate(std::vector<Token> const& tokens)
{
    std::vector<float> stack;
    for (Token const &token : tokens)
    {
        if (token.type == TokenType::OPERAND)
        {
            stack.push_back(token.value);
        }
        else
        {
            float rightOperand = stack.back();
            stack.pop_back();
            float leftOperand = stack.back();
            stack.pop_back();
            switch (token.op)
            {
            case Operator::ADD:
                stack.push_back(leftOperand + rightOperand);
                break;
            case Operator::SUB:
                stack.push_back(leftOperand - rightOperand);
                break;
            case Operator::MUL:
                stack.push_back(leftOperand * rightOperand);
                break;
            case Operator::DIV:
                stack.push_back(leftOperand / rightOperand);
                break;
            default:
                break;
            }
        }
    }
    return stack.back();
}
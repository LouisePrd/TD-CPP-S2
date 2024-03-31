#include "token.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iterator>
#include <cctype>

std::vector<std::string> split_string(std::string const &s)
{
    std::istringstream in(s);
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

float npi_evaluate(std::vector<std::string> const &tokens)
{
    std::vector<float> stack;
    for (std::string const &token : tokens)
    {
        if (is_floating(token))
        {
            stack.push_back(std::stof(token));
        }
        else
        {
            float rightOperand = stack.back();
            stack.pop_back();
            float leftOperand = stack.back();
            stack.pop_back();
            switch (token[0])
            {
            case '+':
                stack.push_back(leftOperand + rightOperand);
                break;
            case '-':
                stack.push_back(leftOperand - rightOperand);
                break;
            case '*':
                stack.push_back(leftOperand * rightOperand);
                break;
            case '/':
                stack.push_back(leftOperand / rightOperand);
                break;
            default:
                break;
            }
        }
    }
    return stack.back();
}

size_t operator_precedence(Operator const op) // on donne la priorité des opérateurs
{
    switch (op)
    {
    case Operator::ADD:
        return 1;
    case Operator::SUB:
        return 1;
    case Operator::MUL:
        return 2;
    case Operator::DIV:
        return 2;
    default:
        return 0;
    }
}

std::vector<Token> infix_to_npi_tokens(std::string const &expression)
{
    std::vector<Token> output;
    std::vector<Token> numbers;
    std::vector<Token> operators;

    output = tokenize(split_string(expression));
    for (Token const &token : output)
    {
        if (token.type != TokenType::OPERAND)
        {
            numbers.push_back(token);
        }
        else
        {
            switch (token.op)
            {
            case Operator::ADD:
                operators.push_back(token);
                break;
            case Operator::SUB:
                operators.push_back(token);
                break;
            case Operator::MUL:
                operators.push_back(token);
                break;
            case Operator::DIV:
                operators.push_back(token);
                break;
            default:
                break;
            }
        }
    }
    operators.insert(operators.end(), numbers.begin(), numbers.end());
    output = operators;
    return output;
}

void calculatriceNPI(std::vector<Token> const &tokens)
{

}

int main()
{
    // Exercice 1
    /*std::string operation;
    std::cout << "Entrez l'operation a evaluer en NPI V1 : ";
    getline(std::cin, operation);
    std::vector<std::string> elements = split_string(operation);
    std::cout << "Resultat : " << npi_evaluate(elements) << std::endl;*/

    // Exercice 2
    /*std::string operation2;
    std::cout << "Entrez l'operation a evaluer en NPI V2 : ";
    getline(std::cin, operation2);
    std::vector<std::string> elements2 = split_string(operation2);
    std::cout << "Resultat : " << npi_evaluate(tokenize(elements2)) << std::endl;*/

    //  Exercice 3
    std::string operation3;
    std::cout << "Conversion en NPI : ";
    getline(std::cin, operation3);
    std::vector<std::string> elements3 = split_string(operation3);
    calculatriceNPI(infix_to_npi_tokens(operation3));
    return 0;
}
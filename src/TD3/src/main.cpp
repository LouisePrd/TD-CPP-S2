#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <iterator>
#include <cctype>

std::vector<std::string> split_string(std::string const &s)
{
    std::istringstream in(s);
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

bool is_floating(std::string const &s)
{
    for (char c : s)
    {
        if (!isdigit(c) && c != '.' && c != ',')
            return false;
    }
    return true;
}

float npi_evaluate(std::vector<std::string> const &tokens)
{
    std::vector<float> stack;
    for (std::string const &token : tokens)
    {
        if (is_floating(token)) // on regarde si nombre ou opérande
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

int main()
{
    // Exercice 1 (Evaluation NPI)
    std::string operation;
    std::cout << "Entrez l'operation a evaluer en NPI :";
    getline(std::cin, operation);
    std::vector<std::string> elements = split_string(operation);
    std::cout << "Resultat : " << npi_evaluate(elements) << std::endl;
    return 0;
}
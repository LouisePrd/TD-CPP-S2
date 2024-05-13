#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>
#include <utility>
#include <functional>
#include "graph.hpp"

int main()
{
    // Exercice 1 (construire un graphe)
    std::vector<std::vector<float>> const &adjacency_matrix = {
        {0.0f, 1.0f, 1.0f},
        {.0f, .0f, 1.0f},
        {.0f, .0f, .0f},
    };
    Graph::WeightedGraph graphMatrix = Graph::build_from_adjacency_matrix(adjacency_matrix);

    Graph::WeightedGraph graph;
    graph.add_vertex(0);
    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_directed_edge(0, 1, 1.0f);
    graph.add_directed_edge(0, 2, 1.0f);
    graph.add_directed_edge(1, 2, 1.0f);

    /*if (graphMatrix == graph)
        std::cout << "Egaux hihi" << std::endl;
    else
        std::cout << "Pas egaux rip" << std::endl;*/

    // Exercice 2 (traverser un graphe)
    std::vector<std::vector<float>> const &adjacency_matrix2 = {
        {0.0f, 1.0f, 1.0f, 0.0f, 0.f, 0.f, 0.f},
        {0.0f, 0.0f, 0.0f, 1.0f, 1.f, 0.f, 0.f},
        {0.0f, 0.0f, 0.0f, 0.0f, 0.f, 1.f, 1.f},
        {0.0f, 0.0f, 0.0f, 0.0f, 0.f, 0.f, 0.f},
        {0.0f, 0.0f, 0.0f, 0.0f, 0.f, 0.f, 0.f},
        {0.0f, 0.0f, 0.0f, 0.0f, 0.f, 0.f, 0.f},
        {0.0f, 0.0f, 0.0f, 0.0f, 0.f, 0.f, 0.f},
    };
    Graph::WeightedGraph graphMatrix2 = Graph::build_from_adjacency_matrix(adjacency_matrix2);

    graphMatrix2.print_DFS(0);
    graphMatrix2.print_BFS(0);
    
    return 0;
}
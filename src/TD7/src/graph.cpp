#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>
#include "graph.hpp"

namespace Graph
{
    bool WeightedGraphEdge::operator==(WeightedGraphEdge const &other) const
    {
        return to == other.to && weight == other.weight;
    }
    bool WeightedGraphEdge::operator!=(WeightedGraphEdge const &other) const
    {
        return !(*this == other);
    }

    bool WeightedGraph::operator==(WeightedGraph const &other) const
    {
        return adjacency_list == other.adjacency_list;
    }

    bool WeightedGraph::operator!=(WeightedGraph const &other) const
    {
        return !(*this == other);
    }
}

// Exercice 1 (construire un graphe)

void Graph::WeightedGraph::add_vertex(int const id)
{
    if (adjacency_list.find(id) == adjacency_list.end())
        adjacency_list[id] = std::vector<WeightedGraphEdge>();
}

void Graph::WeightedGraph::add_directed_edge(int const from, int const to, float const weight)
{
    // Vérifie que les sommets existent, sinon on les crée
    add_vertex(from);
    add_vertex(to);
    WeightedGraphEdge edge{to, weight};
    adjacency_list[from].push_back(edge);
}

void Graph::WeightedGraph::add_undirected_edge(int const from, int const to, float const weight)
{
    add_directed_edge(from, to, weight);
    add_directed_edge(to, from, weight);   
}

Graph::WeightedGraph Graph::build_from_adjacency_matrix(std::vector<std::vector<float>> const &adjacency_matrix)
{
    Graph::WeightedGraph graph;

    for (unsigned int i = 0; i < adjacency_matrix.size(); i++)
    {
        graph.add_vertex(i);
        for (unsigned int j = 0; j < adjacency_matrix[i].size(); j++)
        {
            if (adjacency_matrix[i][j] != 0)
            {
                graph.add_directed_edge(i, j, adjacency_matrix[i][j]);
            }
        }
    }
    return graph;
}

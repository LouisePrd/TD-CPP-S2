#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>
#include <queue>
#include <stack>
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

void Graph::WeightedGraph::print_DFS(int const start) const
{
    std::stack<int> file;
    std::vector<int> sommetsVisités;

    file.push(start);
    while (!file.empty())
    {
        sommetsVisités.push_back(file.top());
        file.pop();

        for (WeightedGraphEdge edge : adjacency_list.at(sommetsVisités.back()))
        {
            if (std::find(sommetsVisités.begin(), sommetsVisités.end(), edge.to) == sommetsVisités.end()) // si le sommet n'a pas déjà été visité
            {
                file.push(edge.to);
            }
        }
    }

    std::cout << "Parcours en profondeur (DFS) : ";
    for (int sommet : sommetsVisités)
    {
        std::cout << sommet << " ";
    }
    std::cout << std::endl;
}

void Graph::WeightedGraph::print_BFS(int const start) const
{
    std::queue<int> queue;
    std::vector<int> sommetsVisités;

    queue.push(start);
    while (!queue.empty())
    {
        sommetsVisités.push_back(queue.front());
        queue.pop();

        for (WeightedGraphEdge edge : adjacency_list.at(sommetsVisités.back()))
        {
            if (std::find(sommetsVisités.begin(), sommetsVisités.end(), edge.to) == sommetsVisités.end())
            {
                queue.push(edge.to);
            }
        }
    }

    std::cout << "Parcours en largeur (BFS) : ";
    for (int sommet : sommetsVisités)
    {
        std::cout << sommet << " ";
    }
    std::cout << std::endl;
}

// Exercice 3 : Dijkstra, algorithme de plus court chemin

std::unordered_map<int, std::pair<float, int>> Graph::dijkstra(WeightedGraph const &graph, int const &start, int const end)
{
    std::unordered_map<int, std::pair<float, int>> distances{};
    std::priority_queue<std::pair<float, int>, std::vector<std::pair<float, int>>, std::greater<std::pair<float, int>>> to_visit{};

    to_visit.push({0, start});
    while (!to_visit.empty())
    {
        auto [current_distance, current_node]{to_visit.top()};
        to_visit.pop();

        if (current_node == end)
        {
            return distances;
        }

        for (WeightedGraphEdge edge : graph.adjacency_list.at(current_node))
        {
            auto find_node{
                distances.find(edge.to)
            };

            bool const visited{
                find_node != distances.end()
            };

            if (!visited)
            {
                int distance = current_distance + edge.weight;
                distances[edge.to] = {distance, current_node};
                to_visit.push({distance, edge.to});

            }
            else
            {
                if (distances[edge.to].first > current_distance + edge.weight)
                {
                    distances[edge.to] = {current_distance + edge.weight, current_node};
                    to_visit.push({current_distance + edge.weight, edge.to});
                }
            }
        }
    }

    return distances;
}
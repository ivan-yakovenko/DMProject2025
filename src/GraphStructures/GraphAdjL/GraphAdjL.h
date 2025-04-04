#pragma once

#include <iostream>

class GraphAdjL {
private:
    int vertices;
    std::vector<std::vector<std::pair<int, int>>> adjacencyList;
public:
    explicit GraphAdjL(int vAmount);

    void addEdge(int u, int v, int weight);

    void printGraph();

    [[nodiscard]] int getVertices() const;

    [[nodiscard]] const std::vector<std::vector<std::pair<int, int>>> &getAdjacencyList() const;
};

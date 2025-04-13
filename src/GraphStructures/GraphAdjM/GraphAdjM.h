#pragma once

#include <iostream>

class GraphAdjM {
private:
    std::vector<std::vector<int>> adjacencyMatrix;
    int vertices;
public:
    explicit GraphAdjM(int vAmount);

    void addEdge(int u, int v, int weight);

    void printGraph();

    [[nodiscard]] int getVertices() const;

    [[nodiscard]] const std::vector<std::vector<int>> &getAdjacencyMatrix() const;
};

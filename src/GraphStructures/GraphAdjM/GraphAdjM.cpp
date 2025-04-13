#include "GraphAdjM.h"

GraphAdjM::GraphAdjM(int vAmount) : vertices(vAmount), adjacencyMatrix(vAmount, std::vector<int>(vAmount, 0)) {}

void GraphAdjM::addEdge(int u, int v, int weight) {
    adjacencyMatrix[u][v] = weight;
}

void GraphAdjM::printGraph() {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (adjacencyMatrix[i][j] != 0) {
                std::cout << i << " -> " << j << ", weight: " << adjacencyMatrix[i][j] << "\n";
            }
        }
    }
}

int GraphAdjM::getVertices() const {
    return this->vertices;
}

const std::vector<std::vector<int>> &GraphAdjM::getAdjacencyMatrix() const {
    return this->adjacencyMatrix;
}
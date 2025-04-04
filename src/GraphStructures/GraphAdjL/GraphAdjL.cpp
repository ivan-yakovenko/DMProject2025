#include "GraphAdjL.h"

GraphAdjL::GraphAdjL(int vAmount) : vertices(vAmount), adjacencyList(vAmount) {}

void GraphAdjL::addEdge(int u, int v, int weight) {
    adjacencyList[u].emplace_back(v, weight);
}

void GraphAdjL::printGraph() {
    for (int i = 0; i < vertices; i++) {
        for (const auto &edge: adjacencyList[i]) {
            std::cout << i << " -> " << edge.first << ", weight: " << edge.second << "\n";
        }
    }
}

int GraphAdjL::getVertices() const {
    return this->vertices;
}

const std::vector<std::vector<std::pair<int, int>>> &GraphAdjL::getAdjacencyList() const {
    return this->adjacencyList;
}
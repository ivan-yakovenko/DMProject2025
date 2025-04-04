#include <iostream>
#include "GraphStructures/GraphAdjL/GraphAdjL.h"
#include <random>

using std::chrono::duration_cast;
using std::chrono::nanoseconds;

GraphAdjL erdosRenyiAlgorithm(int n, double p) {
    GraphAdjL graph(n);
    std::random_device rd;
    std::mt19937 mt(rd());
    std::bernoulli_distribution bd(p);
    std::uniform_int_distribution<int> weights(INT_MIN, INT_MAX);

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (u != v && bd(mt)) {
                int w = weights(mt);
                graph.addEdge(u, v, w);
            }
        }
    }

    return graph;
}

std::vector<long long> bellmanFordAlgorithm(GraphAdjL &graph, int source) {

    std::vector<long long> distances(graph.getVertices(), LONG_LONG_MAX);
    distances[source] = 0;

    for (int i = 1; i < graph.getVertices(); i++) {
        for (int u = 0; u < graph.getVertices(); u++) {
            for (const auto &edge: graph.getAdjacencyList()[u]) {
                if (distances[u] != LONG_LONG_MAX && distances[u] + edge.second < distances[edge.first]) {
                    distances[edge.first] = distances[u] + edge.second;
                }
            }
        }
    }

    for (int u = 0; u < graph.getVertices(); u++) {
        for (const auto &edge: graph.getAdjacencyList()[u]) {
            if (distances[u] != LONG_LONG_MAX && distances[u] + edge.second < distances[edge.first]) {
                return {};
            }
        }
    }

    return distances;
}


int main() {
    int vertices[10] = {20, 40, 60, 80, 100, 120, 140, 160, 180, 200};
    double densities[5] = {0.6, 0.7, 0.8, 0.9, 1};

    for (int vertice: vertices) {
        for (double density: densities) {
            for (int i = 1; i <= 20; i++) {
                GraphAdjL graph = erdosRenyiAlgorithm(vertice, density);

                auto startTimer = std::chrono::high_resolution_clock::now();

                std::vector<long long> res = bellmanFordAlgorithm(graph, 0);

                auto endTimer = std::chrono::high_resolution_clock::now();

                auto execTime = duration_cast<nanoseconds>(endTimer - startTimer);

                std::cout << "Amount of vertices: " << vertice << ", density: " << density << ", attempt: " << i
                          << ", time: "
                          << double(execTime.count()) * 1e-9 << " seconds\n\n";
            }
        }
    }
}
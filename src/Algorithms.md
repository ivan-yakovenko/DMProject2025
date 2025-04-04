# Algorithms and tests

## Overview

---

This markdown file provides an explanation of the implemented algorithms and tests in the [**GraphAdjLexec.cpp**](GraphAdjLexec.cpp) and [**GraphAdjMexec.cpp**](GraphAdjMexec.cpp) executables.  

---

### Using adjacency matrix

- [**GraphAdjMexec.cpp**](GraphAdjMexec.cpp) - is an executable file, which is responsible for implementation of algorithms and tests for adjacency matrix graph representation.

**Description**

- _**erdosRenyiAlgorithm**_ - a modified Erdos-Renyi algorithm, which generates a graph, based on amount of vertices and density provided.
- _**bellmanFordAlgorithm**_ - Bellman-Ford algorithm implementation, which finds a shortest paths from a source to each possible destination, in case of negative cycle occurring, returns an empty vector.
- _**tests**_ - conducted tests on ten different vertices, applying five different densities to each of them, with 20 attempts for each vertex-density pair

```cpp
int main() {
    int vertices[10] = {20, 40, 60, 80, 100, 120, 140, 160, 180, 200};
    double densities[5] = {0.6, 0.7, 0.8, 0.9, 1};

    for (int vertice: vertices) {
        for (double density: densities) {
            for (int i = 1; i <= 20; i++) {
                GraphAdjM graph = erdosRenyiAlgorithm(vertice, density);

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
```
- _**Bellman-Ford algorithm complexity**: **O(V<sup>3</sup>)**, (V = vertices)_

---

### Using adjacency lists

- [**GraphAdjLexec.cpp**](GraphAdjLexec.cpp) - is an executable file, which is responsible for implementation of algorithms and tests for adjacency lists graph representation.

**Description**

- _**erdosRenyiAlgorithm**_ - a modified Erdos-Renyi algorithm, which generates a graph, based on amount of vertices and density provided.
- _**bellmanFordAlgorithm**_ - Bellman-Ford algorithm implementation, which finds a shortest paths from a source to each possible destination, in case of negative cycle occurring, returns an empty vector.
- _**tests**_ - conducted tests on ten different vertices, applying five different densities to each of them, with 20 attempts for each vertex-density pair

```cpp
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
```
- _**Bellman-Ford algorithm complexity**: **O(VE)**, (V = vertices, E = edges)_  


#ifndef GRAPH_SOLVER_H
#define GRAPH_SOLVER_H

#include <cstddef>
#include <utility>
#include <vector>
#include <iostream>

class GraphSolver {
public:
    GraphSolver(): vertexCount(0), edgeCount(0), adjacencyMatrix(nullptr), vertexColors(nullptr), colorAvailability(nullptr), maxColorCount(0) {}
    GraphSolver(int numVertices, int numEdges, int** matrix):
        vertexCount(numVertices), edgeCount(numEdges), adjacencyMatrix(matrix),
        vertexColors(new int[numVertices]), colorAvailability(new int[numVertices]), maxColorCount(0) {}

    void InitializeData(int numVertices, int numEdges, int** matrix);
    void ReleaseResources();
    ~GraphSolver() { ReleaseResources(); }
    void ExecuteColoring();
    void ComputeMaximumColoring();
    int VertexCount() const { return vertexCount; }
    int* VertexColors() const { return vertexColors; }
    int MaximumColorCount() const { return maxColorCount; }

private:
    int vertexCount;
    int edgeCount;
    int** adjacencyMatrix;
    int* vertexColors;
    int* colorAvailability;
    int maxColorCount;
};

#endif // GRAPH_SOLVER_H

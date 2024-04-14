#include "solver.h"

void GraphSolver::InitializeData(int numVertices, int numEdges, int** matrix) {
    this->ReleaseResources();

    vertexCount = numVertices;
    edgeCount = numEdges;
    if (vertexCount <= 0 || edgeCount <= 0)
        return;

    adjacencyMatrix = matrix;
    vertexColors = new int[vertexCount];
    std::fill_n(vertexColors, vertexCount, -1);
    colorAvailability = new int[vertexCount];
    std::fill_n(colorAvailability, vertexCount, 1);
}

void GraphSolver::ReleaseResources() {
    vertexCount = 0;
    edgeCount = 0;
    adjacencyMatrix = nullptr;
    delete[] vertexColors;
    vertexColors = nullptr;
    delete[] colorAvailability;
    colorAvailability = nullptr;
}

void GraphSolver::ExecuteColoring() {
    if (vertexCount <= 0 || edgeCount <= 0 || adjacencyMatrix == nullptr || vertexColors == nullptr)
        return;

    vertexColors[0] = 0;

    for (int v = 0; v < vertexCount; v++) {
        std::fill_n(colorAvailability, vertexCount, 1);

        for (int i = 0; i < vertexCount; i++) {
            if (adjacencyMatrix[v][i] == 1 && vertexColors[i] != -1)
                colorAvailability[vertexColors[i]] = 0;
        }

        int cr;

        for (cr = 0; cr < vertexCount; cr++) {
            if (colorAvailability[cr] == 1)
                break;
        }

        vertexColors[v] = cr;
    }
}

void GraphSolver::ComputeMaximumColoring() {
    for (int i = 0; i < vertexCount; i++) {
        if (vertexColors[i] > maxColorCount) {
            maxColorCount = vertexColors[i];
        }
    }
    maxColorCount++;
}

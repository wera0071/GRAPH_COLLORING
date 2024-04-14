#include "parser.h"

void GraphParser::AllocateResources() {
    if (vertexCount <= 0)
        return;
    if (edgeCount <=0)
        return;

    adjacencyMatrix = new int*[vertexCount];
    for(int i = 0; i < vertexCount; i++){
        adjacencyMatrix[i] = new int[vertexCount];
        std::fill_n(adjacencyMatrix[i], vertexCount, 0);
    }
}

void GraphParser::ReleaseResources() {
    if (adjacencyMatrix == nullptr)
        return;

    for(int i = 0; i < vertexCount; i++)
        if (adjacencyMatrix[i] != nullptr)
            delete [] adjacencyMatrix[i];

    delete [] adjacencyMatrix;
    adjacencyMatrix = nullptr;
    vertexCount = 0;
    edgeCount = 0;
}

void GraphParser::ReadFromFile(const std::string& filename) {
    this->ReleaseResources();

    std::ifstream fileStream(filename);

    fileStream >> vertexCount;
    fileStream >> edgeCount;
    this->AllocateResources();

    edgePairs.reserve(edgeCount);
    for(int i = 0; i < edgeCount; i++) {
        int u, v;
        fileStream >> u >> v;
        edgePairs.emplace_back(std::make_pair(u, v));
    }

    fileStream.close();
}

void GraphParser::PopulateMatrix() {
    if (vertexCount <= 0)
        return;
    if (edgeCount <= 0)
        return;
    if (adjacencyMatrix == nullptr)
        return;

    for (int i = 0 ; i < edgeCount; i++){
        adjacencyMatrix[edgePairs[i].first][edgePairs[i].second] = 1;
        adjacencyMatrix[edgePairs[i].second][edgePairs[i].first] = 1;
    }
}

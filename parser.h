#ifndef GRAPH_PARSER_H
#define GRAPH_PARSER_H

#include <fstream>
#include <vector>
#include <utility>

class GraphParser {
public:
    GraphParser() : vertexCount(0), edgeCount(0), adjacencyMatrix(nullptr) {}
    void AllocateResources();
    void ReleaseResources();
    ~GraphParser() { ReleaseResources(); }
    void ReadFromFile(const std::string& filename);
    void PopulateMatrix();
    int VertexCount() const { return vertexCount; }
    int EdgeCount() const { return edgeCount; }
    std::vector<std::pair<int, int>>& EdgeList() { return edgePairs; }
    int** Matrix() { return adjacencyMatrix; }

private:
    int vertexCount;
    int edgeCount;
    std::vector<std::pair<int, int>> edgePairs;
    int** adjacencyMatrix;
};

#endif // GRAPH_PARSER_H

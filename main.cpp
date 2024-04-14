#include "parser.h"
#include "solver.h"

#include <iostream>
#include <vector>
#include <utility>

int main() {
    GraphParser graphParser;
    GraphSolver graphSolver;
    std::string filename;

    std::cout << "Введите имя файла с графом: ";
    std::cin >> filename;

    graphParser.ReadFromFile(filename);
    graphParser.PopulateMatrix();

    int numVertices = graphParser.VertexCount();
    int numEdges = graphParser.EdgeCount();
    int** matrix = graphParser.Matrix();
    auto edges = graphParser.EdgeList();
    graphSolver.InitializeData(numVertices, numEdges, matrix);
    graphSolver.ExecuteColoring();
    graphSolver.ComputeMaximumColoring();
    int* colors = graphSolver.VertexColors();
    int maxColorCount = graphSolver.MaximumColorCount();

    // Вывод цветов вершин
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Вершина " << i << " окрашена в цвет " << colors[i] << std::endl;
    }

    // Вывод максимального количества цветов, использованных для раскраски графа
    std::cout << "Максимальное количество использованных цветов: " << maxColorCount << std::endl;

    return 0;
}

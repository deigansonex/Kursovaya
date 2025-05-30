#include "Graph.h"

int main() {
    Graph g;

    // Добавляем рёбра между вершинами (граф неориентированный)
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 6);
    g.addEdge(6, 4);
    g.addEdge(4, 5);


    // Обход графа в глубину начиная с вершины 1
    g.DFS(1);

    // Поиск пути от вершины 1 до вершины 5
    auto path = g.findPathDFS(6, 5);

    std::cout << "Path from 6 to 5 (DFS): ";
    for (int v : path) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}

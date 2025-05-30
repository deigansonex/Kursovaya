#pragma once  // Гарантирует, что этот файл подключается только один раз при компиляции

#include <iostream>              // Для вывода на экран
#include <unordered_map>        // Для хранения списка смежности
#include <vector>               // Для хранения соседей каждой вершины
#include <stack>                // Для обхода графа в глубину (DFS)
#include <set>                  // Для отслеживания посещённых вершин
#include <algorithm>            // Для функции reverse()

// Класс Graph реализует простой неориентированный граф
class Graph {
private:
    // Список смежности: каждой вершине соответствует вектор её соседей
    std::unordered_map<int, std::vector<int>> adj;

public:
    // Добавляет вершину в граф (если её ещё нет)
    void addVertex(int v);

    // Добавляет неориентированное ребро между двумя вершинами
    void addEdge(int u, int v);

    // Выполняет обход графа в глубину (DFS), начиная с вершины start
    void DFS(int start);

    // Ищет путь между двумя вершинами, используя обход в глубину (DFS)
    std::vector<int> findPathDFS(int start, int end);
};

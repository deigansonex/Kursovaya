#include "Graph.h"

// Добавление вершины в граф
void Graph::addVertex(int v) {
    adj[v];  // Создаёт пустой список соседей для вершины v, если её ещё нет
}

// Добавление неориентированного ребра
void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);  // Добавляем v в список соседей u
    adj[v].push_back(u);  // Добавляем u в список соседей v (т.к. граф неориентированный)
}

// Обход графа в глубину (итеративный вариант через стек)
void Graph::DFS(int start) {
    std::set<int> visited;         // Множество для хранения уже посещённых вершин
    std::stack<int> stack;         // Стек для обхода в глубину
    stack.push(start);             // Начинаем с указанной вершины

    std::cout << "DFS: ";

    while (!stack.empty()) {
        int v = stack.top();       // Получаем верхнюю вершину из стека
        stack.pop();               // Удаляем её из стека

        if (visited.count(v) == 0) {  // Если вершина ещё не была посещена
            std::cout << v << " ";    // Печатаем её
            visited.insert(v);       // Отмечаем как посещённую

            // Перебираем соседей текущей вершины
            for (int neighbor : adj[v]) {
                if (visited.count(neighbor) == 0) {
                    stack.push(neighbor);  // Добавляем непосещённого соседа в стек
                }
            }
        }
    }

    std::cout << std::endl;
}

// Поиск пути между двумя вершинами с помощью DFS
std::vector<int> Graph::findPathDFS(int start, int end) {
    std::unordered_map<int, int> parent;  // Храним откуда пришли в каждую вершину
    std::set<int> visited;                // Посещённые вершины
    std::stack<int> stack;                // Стек для DFS
    stack.push(start);                    // Начинаем с вершины start
    visited.insert(start);                // Отмечаем её как посещённую

    // Основной цикл DFS
    while (!stack.empty()) {
        int v = stack.top();
        stack.pop();

        if (v == end) break;  // Если достигли нужной вершины — выходим

        for (int neighbor : adj[v]) {
            if (visited.count(neighbor) == 0) {
                visited.insert(neighbor);     // Отмечаем соседа как посещённого
                parent[neighbor] = v;         // Запоминаем, откуда мы пришли к нему
                stack.push(neighbor);         // Добавляем соседа в стек
            }
        }
    }

    // Если вершина end не была достигнута, путь не найден
    if (visited.count(end) == 0) return {};

    // Восстанавливаем путь от end до start, используя parent
    std::vector<int> path;
    for (int at = end; at != start; at = parent[at]) {
        path.push_back(at);
    }
    path.push_back(start);

    std::reverse(path.begin(), path.end());  // Путь был от конца к началу — переворачиваем

    return path;
}

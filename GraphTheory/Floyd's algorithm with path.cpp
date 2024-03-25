#include <iostream>
#include <cinttypes>
#include <vector>
#include <map>

struct edge {
  char to;
  int64_t cost;
};

void Floyd(std::vector<std::vector<int64_t>>& graph_matrix, std::vector<std::vector<int32_t>>& next) {
    size_t n = graph_matrix.size();

    for (size_t k = 0; k < n; ++k) {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                if (graph_matrix[i][k] + graph_matrix[k][j] < graph_matrix[i][j]) {
                    graph_matrix[i][j] = graph_matrix[i][k] + graph_matrix[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

void Print32_tShortestPath(const std::vector<std::vector<int32_t>>& next, char from, char to) {
    if (next[from - 'a'][to - 'a'] == -1) {
        std::cout << "There is no path between " << from << " and " << to << std::endl;
        return;
    }

    std::vector<char> path;
    path.push_back(from);
    int32_t current = (from == 'z' ? 'u' - 'a' : from - 'a');
    while (char(current + 'a') != (to == 'z' ? 'u' : to)) {
        current = next[current][(to == 'z' ? 'u' - 'a' : to - 'a')];
        path.push_back(char(current + 'a' == 'u' ? 'z' : current + 'a'));
    }

    std::cout << "Shortest path between " << from << " and " << to << ": ";
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i];
        if (i != path.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

int32_t main() {
    std::map<char, std::vector<edge>> adjacency_list = {
        {'a', {{'b', 2}, {'c', 4}, {'d', 1}}},
        {'b', {{'a', 2}, {'c', 3}, {'e', 1}}},
        {'c', {{'a', 4}, {'b', 3}, {'e', 2}, {'f', 2}, }},
        {'d', {{'a', 1}, {'f', 5}, {'g', 4}}},
        {'e', {{'b', 1}, {'c', 2}, {'h', 3}}},
        {'f', {{'c', 2}, {'d', 5}, {'g', 3}, {'h', 3}, {'i', 2}, {'j', 4}}},
        {'g', {{'d', 4}, {'f', 3}, {'k', 2}}},
        {'h', {{'e', 3}, {'f', 3}, {'l', 1}, {'o', 8}}},
        {'i', {{'f', 2}, {'j', 3}, {'l', 3}, {'m', 2}}},
        {'j', {{'f', 4}, {'i', 3}, {'k', 6}, {'m', 6}, {'n', 3}}},
        {'k', {{'g', 2}, {'j', 6}, {'n', 4}, {'r', 2}}},
        {'l', {{'h', 1}, {'i', 3}, {'o', 6}, {'m', 3}}},
        {'m', {{'i', 2}, {'j', 6}, {'l', 3}, {'n', 5}, {'o', 4}, {'p', 2}}},
        {'n', {{'j', 3}, {'k', 4}, {'m', 5}, {'q', 2}, {'r', 1}}},
        {'o', {{'h', 8}, {'l', 6}, {'m', 4}, {'p', 2}, {'s', 6}}},
        {'p', {{'m', 2}, {'o', 2}, {'q', 1}, {'s', 2}, {'t', 1}}},
        {'q', {{'n', 2}, {'p', 1}, {'r', 8}, {'t', 3}}},
        {'r', {{'k', 2}, {'n', 1}, {'q', 8}, {'t', 5}}},
        {'s', {{'o', 6}, {'p', 2}, {'u', 2}}},
        {'t', {{'p', 1}, {'q', 3}, {'r', 5}, {'u', 8}}},
        {'u', {{'s', 2}, {'t', 8}}}
    };

    std::vector<std::vector<int32_t>> next(21, std::vector<int32_t>(21, -1));
    std::vector<std::vector<int64_t>> graph_matrix(21, std::vector<int64_t>(21, INT_MAX));
    for (size_t i = 0; i < graph_matrix.size(); ++i) {
        graph_matrix[i][i] = 0;
        next[i][i] = i;
    }
    for (const auto& [from, edges] : adjacency_list) {
        for (const auto& edge : edges) {
            graph_matrix[from - 'a'][edge.to - 'a'] = edge.cost;
            graph_matrix[edge.to - 'a'][from - 'a'] = edge.cost;
            next[from - 'a'][edge.to - 'a'] = edge.to - 'a';
            next[edge.to - 'a'][from - 'a'] = from - 'a';
        }
    }

    Floyd(graph_matrix, next);

    char from, to;
    std::cout << "Enter source vertex (from): ";
    std::cin >> from;
    std::cout << "Enter destination vertex (to): ";
    std::cin >> to;

    Print32_tShortestPath(next, from, to);
}

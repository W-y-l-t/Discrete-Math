

#include <iostream>
#include <cinttypes>
#include <vector>
#include <map>
#include <set>

struct edge {
    char to;
    int64_t cost;
};

void Floyd(std::vector<std::vector<int64_t>>& graph_matrix) {
    size_t n = graph_matrix.size();

    for (size_t k = 0; k < n; ++k) {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                graph_matrix[i][j] = std::min(graph_matrix[i][j], graph_matrix[i][k] + graph_matrix[k][j]);
            }
        }
    }
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

    std::vector<std::vector<int64_t>> graph_matrix(21, std::vector<int64_t>(21, INT_MAX));
    for (size_t i = 0; i < graph_matrix.size(); ++i) {
        graph_matrix[i][i] = 0;
    }
    for (const auto& [from, edges] : adjacency_list) {
        for (const auto& edge : edges) {
            graph_matrix[from - 'a'][edge.to - 'a'] = edge.cost;
            graph_matrix[edge.to - 'a'][from - 'a'] = edge.cost;
        }
    }

    Floyd(graph_matrix);

    std::cout << "  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  z\n";
    for (size_t i = 0; i < graph_matrix.size(); ++i) {
        std::cout << (char('a' + i) == 'u' ? 'z' : char('a' + i)) << ' ';
        for (size_t j = 0; j < graph_matrix.size(); ++j) {
            std::cout << graph_matrix[i][j] << (std::to_string(graph_matrix[i][j]).size() == 1 ? "  " : " ");
        }
        std::cout << '\n';
    }
}

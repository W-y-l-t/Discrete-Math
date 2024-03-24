/*
* Time Complexity: O(E log V),
 * where V - count of vertexes,
 * E - count of edges in graph
 *
 * Auxiliary Space: O(V)
 */

#include <iostream>
#include <cinttypes>
#include <vector>
#include <map>
#include <set>

struct edge {
    char to;
    int64_t cost;
};

void Dijkstra(char from, char to, std::map<char, std::vector<edge>> &graph) {

    std::map<char, int64_t> dists = {{'a', LLONG_MAX}, {'b', LLONG_MAX}, {'c', LLONG_MAX}, {'d', LLONG_MAX},
                                     {'e', LLONG_MAX}, {'f', LLONG_MAX}, {'g', LLONG_MAX}, {'h', LLONG_MAX},
                                     {'i', LLONG_MAX}, {'j', LLONG_MAX}, {'k', LLONG_MAX}, {'l', LLONG_MAX},
                                     {'m', LLONG_MAX}, {'n', LLONG_MAX}, {'o', LLONG_MAX}, {'p', LLONG_MAX},
                                     {'q', LLONG_MAX}, {'r', LLONG_MAX}, {'s', LLONG_MAX}, {'t', LLONG_MAX},
                                     {'z', LLONG_MAX}};
    std::map<char, bool> used;
    std::set<std::pair<int64_t, char>> queue;
    queue.emplace(0, from);
    dists[from] = 0;

    while (!queue.empty()) {
        auto [len, current] = *queue.begin();
        queue.erase(queue.begin());

        if (used.contains(current)) {
            continue;
        }
        used[current] = true;

        for (auto &e : graph[current]) {
            if (dists[e.to] > dists[current] + e.cost) {

                dists[e.to] = dists[current] + e.cost;
                queue.emplace(dists[e.to], e.to);
            }
        }
    }

    std::cout << "Shortest path length from " << from << " to: " << to << " is: ";
    std::cout << dists[to] << "\n";
    std::cout << "Path is: ";
    char current = to;
    while (current != from) {
        std::cout << current << " <- ";
        for (auto &e : graph[current]) {
            if (dists[current] == dists[e.to] + e.cost) {
                current = e.to;
                break;
            }
        }
    }
    std::cout << from << "\n";
}

int32_t main() {
    std::map<char, std::vector<edge>> graph = {
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
        {'s', {{'o', 6}, {'p', 2}, {'z', 2}}},
        {'t', {{'p', 1}, {'q', 3}, {'r', 5}, {'z', 8}}},
        {'z', {{'s', 2}, {'t', 8}}}
    };

    char from = 'a';
    char to = 'z';

    Dijkstra(from, to, graph);
}

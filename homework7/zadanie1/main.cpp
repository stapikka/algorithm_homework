#include <iostream>
#include <fstream>
#include <vector>

void dfs(int v, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::vector<int>& order) {
    visited[v] = true;
    order.push_back(v + 1);
    for(int u = 0; u < adj.size(); ++u) {
        if(adj[v][u] == 1 && !visited[u]) {
            dfs(u, adj, visited, order);
        }
    }
}

int main() {
    std::ifstream fin("input.txt");
    if(!fin.is_open()) {
        std::cerr << "Invalid file!" << std::endl;
        return 1;
    }
    int N;
    fin >> N;

    std::vector<std::vector<int>> adj(N, std::vector<int>(N));
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            fin >> adj[i][j];
        }
    }
    std::vector<bool> visited(N, false);
    std::vector<int> order;

    dfs(0, adj, visited, order);

    std::cout << "Result: ";
    for(int v : order) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}
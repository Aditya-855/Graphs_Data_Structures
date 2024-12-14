//
// Created by Aditya on 14-12-2024.
//

#include "Bipartite_Graph_BFS.h"
#include <iostream>
#include <vector>
#include <queue> // Required for std::queue
using namespace std;

class Solution {
public:
    bool checkBipartiteBFS(vector<vector<int>>& adj, int curr, vector<int>& color, int currColor) {
        queue<int> que;
        que.push(curr);
        color[curr] = currColor;

        while (!que.empty()) {
            int u = que.front();
            que.pop();

            for (int& v : adj[u]) {
                if (color[v] == color[u]) {
                    return false;
                } else if (color[v] == -1) { // not visited yet
                    color[v] = 1 - color[u];
                    que.push(v);
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> color(V, -1); // all vertices initially uncolored

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!checkBipartiteBFS(adj, i, color, 1)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Example graph: adjacency list representation
    // Graph: 0 -- 1
    //        |    |
    //        3 -- 2
    vector<vector<int>> graph = {
        {1, 3}, // edges for vertex 0
        {0, 2}, // edges for vertex 1
        {1, 3}, // edges for vertex 2
        {0, 2}  // edges for vertex 3
    };

    if (sol.isBipartite(graph)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}

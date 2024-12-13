//
// Created by Aditya on 13-12-2024.
//

#include "Is_Graph_Bipartite.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkBipartiteDFS(vector<vector<int>>& graph, int curr, vector<int>& color, int currColor) {
        color[curr] = currColor; // Color the current node

        // Visit adjacent nodes
        for (int &v : graph[curr]) {
            if (color[v] == color[curr]) {
                return false; // Adjacent nodes cannot have the same color
            }

            if (color[v] == -1) { // Not visited
                int colorOfV = 1 - currColor; // Alternate color

                if (!checkBipartiteDFS(graph, v, color, colorOfV)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size(); // Get the number of nodes
        vector<int> color(V, -1); // Initialize all nodes as uncolored

        // Check all components of the graph
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) { // If not visited
                if (!checkBipartiteDFS(graph, i, color, 1)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    // Example 1: Bipartite graph
    vector<vector<int>> graph1 = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    // Example 2: Non-bipartite graph
    vector<vector<int>> graph2 = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}
    };

    cout << "Graph 1: " << (solution.isBipartite(graph1) ? "Bipartite" : "Not Bipartite") << endl;
    cout << "Graph 2: " << (solution.isBipartite(graph2) ? "Bipartite" : "Not Bipartite") << endl;

    return 0;
}

//
// Created by adity on 30-11-2024.
//

#include "Course_Schedule_DFS.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isCycleDFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &inRec) {
        visited[u] = true;
        inRec[u] = true;

        for (int &v : adj[u]) {
            // If not visited, perform DFS on v
            if (!visited[v] && isCycleDFS(adj, v, visited, inRec))
                return true; // Cycle detected

            else if (inRec[v])
                return true;
        }

        inRec[u] = false;
        return false; // No cycle detected
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRec(numCourses, false);

        for (auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            // b --> a
            adj[b].push_back(a);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && isCycleDFS(adj, i, visited, inRec))
                return false; // Cannot complete all courses
        }

        return true; // All courses can be completed
    }
};

int main() {
    Solution solution;

    // Test case 1
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "Can finish courses (Test case 1): " << (solution.canFinish(numCourses1, prerequisites1) ? "true" : "false") << endl;

    // Test case 2
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << "Can finish courses (Test case 2): " << (solution.canFinish(numCourses2, prerequisites2) ? "true" : "false") << endl;

    // Test case 3
    int numCourses3 = 4;
    vector<vector<int>> prerequisites3 = {{1, 0}, {2, 1}, {3, 2}};
    cout << "Can finish courses (Test case 3): " << (solution.canFinish(numCourses3, prerequisites3) ? "true" : "false") << endl;

    // Test case 4
    int numCourses4 = 4;
    vector<vector<int>> prerequisites4 = {{1, 0}, {2, 1}, {3, 2}, {1, 3}};
    cout << "Can finish courses (Test case 4): " << (solution.canFinish(numCourses4, prerequisites4) ? "true" : "false") << endl;

    return 0;
}

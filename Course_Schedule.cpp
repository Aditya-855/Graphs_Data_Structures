//
// Created by adity on 29-11-2024.
//

#include "Course_Schedule.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    bool topologicalSortCheck(unordered_map<int, vector<int>> adj, int n, vector<int>& indegree) {
        queue<int> que;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                count++;
                que.push(i);
            }
        }

        while (!que.empty()) {
            int u = que.front();
            que.pop();

            for (int& v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    count++;
                    que.push(v);
                }
            }
        }

        return count == n; // True if all nodes can be visited
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj; // Adjacency list for graph
        vector<int> indegree(numCourses, 0); // Indegree array for Kahn's algorithm

        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a); // b --> a
            indegree[a]++;
        }

        return topologicalSortCheck(adj, numCourses, indegree);
    }
};

int main() {
    Solution solution;

    int numCourses = 4; // Example number of courses
    vector<vector<int>> prerequisites = {
        {1, 0}, {2, 1}, {3, 2} // Example prerequisites
    };

    if (solution.canFinish(numCourses, prerequisites)) {
        cout << "All courses can be finished." << endl;
    } else {
        cout << "Not all courses can be finished due to a cycle." << endl;
    }

    return 0;
}

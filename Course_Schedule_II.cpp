//
// Created by adity on 29-11-2024.
//

#include "Course_Schedule_II.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Course_Schedule_2 {
public:
    vector<int> topologicalSort(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree) {
        queue<int> que;
        vector<int> result;
        int count = 0;

        // Push nodes with indegree 0 into the queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                result.push_back(i);
                count++;
                que.push(i);
            }
        }

        // Process nodes in the queue
        while (!que.empty()) {
            int u = que.front();
            que.pop();

            for (int &v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    result.push_back(v);
                    count++;
                    que.push(v);
                }
            }
        }

        // If all courses are processed, return the order
        if (count == n)
            return result;

        // Cycle detected, return an empty array
        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        // Build the adjacency list and calculate indegree
        for (auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        return topologicalSort(adj, numCourses, indegree);
    }
};

int main() {
    Course_Schedule_2 solution;

    // Test case 1
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    vector<int> result = solution.findOrder(numCourses, prerequisites);
    cout << "Course order: ";
    if (result.empty()) {
        cout << "No valid order (cycle detected)" << endl;
    } else {
        for (int course : result) {
            cout << course << " ";
        }
        cout << endl;
    }

    // Test case 2 (cycle example)
    numCourses = 2;
    prerequisites = {{1, 0}, {0, 1}};
    result = solution.findOrder(numCourses, prerequisites);
    cout << "Course order: ";
    if (result.empty()) {
        cout << "No valid order (cycle detected)" << endl;
    } else {
        for (int course : result) {
            cout << course << " ";
        }
        cout << endl;
    }
    return 0;
}

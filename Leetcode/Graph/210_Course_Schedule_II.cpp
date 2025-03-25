#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> adj(numCourses);
            vector<int> state(numCourses, 0); // 0 = unvisited, 1 = visiting, 2 = visited
            vector<int> order; // Topological order
            bool hasCycle = false; // detect cycle
    
            // Build adjacency list
            // When you want to implement a graph, use adjacency list.
            for (const auto& pre : prerequisites) {
                adj[pre[1]].push_back(pre[0]);
            }
    
            // DFS from all unvisited nodes
            for (int i = 0; i < numCourses; i++) {
                if (state[i] == 0) {
                    dfs(i, adj, state, order, hasCycle);
                    if (hasCycle) return {}; // Cycle detected, no valid order
                }
            }
    
            reverse(order.begin(), order.end()); // Reverse for correct order
            return order;
        }
    
    private:
        void dfs(int course, vector<vector<int>>& adj, vector<int>& state, vector<int>& order, bool& hasCycle) {
            if (state[course] == 1) { // Cycle detected
                hasCycle = true;
                return;
            }
            if (state[course] == 2) return; // Already processed
    
            state[course] = 1; // Mark as visiting
            for (int next : adj[course]) {
                dfs(next, adj, state, order, hasCycle);
                if (hasCycle) return;
            }
    
            state[course] = 2; // Mark as visited
            order.push_back(course);
        }
    };

int main() {
    Solution solution;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    
    vector<int> order = solution.findOrder(numCourses, prerequisites);
    
    if (order.empty()) {
        cout << "No valid order found." << endl;
    } else {
        cout << "Course order: ";
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    }
    
    return 0;
}
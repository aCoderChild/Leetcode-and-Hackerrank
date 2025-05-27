// Leetcode problem number: 1857
// Leetcode problem title: Largest Color Value in a Directed Graph
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);

        // Build adjacency list and in-degree
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            inDegree[e[1]]++;
        }

        queue<int> q;
        vector<vector<int>> dp(n, vector<int>(26, 0)); // dp[node][color]
        
        // Initialize nodes with inDegree 0
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        int processed = 0;
        int res = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            processed++;

            int color = colors[u] - 'a';
            dp[u][color]++;
            res = max(res, dp[u][color]);

            for (int v : adj[u]) {
                for (int c = 0; c < 26; ++c) {
                    dp[v][c] = max(dp[v][c], dp[u][c]);
                }
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return (processed == n) ? res : -1; // Cycle check
    }
};

//----- More Optimised Version -----
// This version uses the same logic but is more concise and efficient.
// Incorporate checking cycles and updating the result in a single pass. ***
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);

        // Build adjacency list and in-degree
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            inDegree[e[1]]++;
        }

        queue<int> q;
        vector<vector<int>> dp(n, vector<int>(26, 0)); // dp[node][color]
        
        // Initialize nodes with inDegree 0
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        int processed = 0;
        int res = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            processed++;

            int color = colors[u] - 'a';
            dp[u][color]++; // Increment the count for the color of the current node
            res = max(res, dp[u][color]);

            for (int v : adj[u]) {
                for (int c = 0; c < 26; ++c) {
                    dp[v][c] = max(dp[v][c], dp[u][c]);
                    // does NOt need to +1 to the color count for v's own colour
                }
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return (processed == n) ? res : -1; // Cycle check
    }
};
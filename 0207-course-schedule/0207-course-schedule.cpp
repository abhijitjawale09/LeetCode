class Solution {
public:
    bool topo(unordered_map<int, vector<int>>& adj, int n, vector<int>& indegree) {
        queue<int> que;
        int count = 0;

        // Add nodes with 0 in-degree to the queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        // Process nodes in topological order
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            count++;  // Increment count for each node processed

            // Decrease the in-degree of adjacent nodes
            for (int& v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        // Check if all nodes were processed
        return count == n;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        // Build the adjacency list and compute in-degrees
        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        // Check if all courses can be finished using topological sort
        return topo(adj, numCourses, indegree);
    }
};

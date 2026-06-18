class Solution {
    vector<vector<int>> adj;
    int result = 0;  // global counter for increments

    long long dfs(int curr, int parent, vector<int>& cost) {
        vector<long long> child;
        for (auto next : adj[curr]) {
            if (next != parent) {
                child.push_back(dfs(next, curr, cost));
            }
        }

        long long maxChild = 0;
        if (!child.empty()) {
            maxChild = *max_element(child.begin(), child.end());
            for (auto val : child) {
                if (val != maxChild) {
                    // increment needed to equalize this child path
                    ++result;
                }
            }
        }

        return maxChild + cost[curr];
    }

public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        adj.resize(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1, cost);
        return result;
    }
};

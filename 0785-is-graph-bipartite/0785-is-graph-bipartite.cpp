class Solution {
public:

    bool checkbipartiteBFS(vector<vector<int>>& adj , int curr ,vector<int> &color , int currcolor  ) {
        queue<int> que;
        que.push(curr);
        color[curr] = currcolor;

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for(int &v : adj) {
                if(color[v] == color[u]) {
                    return false;
                }else if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    que.push(v);
                }
            }
            return true;
        }
    }
    
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> color(V , -1);
        for(int i = 0; i < V; i++) {
            if(color[i] == -1) {
                if(checkbipartiteBFS(adj ,i , color , 1) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};
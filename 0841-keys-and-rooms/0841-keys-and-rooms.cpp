class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // unordered_map<int , vector<int>> adj;

        int n = rooms.size();

        vector<bool> vis(n, false);
        queue<int> que;
        que.push(0);
        // vis[0] = true;

        while(!que.empty()) {
            int top = que.front();
            que.pop();
            vis[top] = true;
            for(int i = 0; i < rooms[top].size(); i++) {
                if(vis[rooms[top][i]] == false) {
                    que.push(rooms[top][i]);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(vis[i] == false) {
                return false;
            }
        }
        return true;
    }
};
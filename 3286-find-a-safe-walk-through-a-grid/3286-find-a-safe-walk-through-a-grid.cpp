class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> best(n, vector<int>(m, -1));

        queue<pair<pair<int,int>, int>> q;

        int startHealth = health - grid[0][0];
        if(startHealth <= 0) return false;

        q.push({{0,0}, startHealth});
        best[0][0] = startHealth;

        vector<pair<int,int>> dirs = {
            {0,1}, {1,0}, {-1,0}, {0,-1}
        };

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            int x = curr.first.first;
            int y = curr.first.second;
            int h = curr.second;

            if(x == n-1 && y == m-1)
                return true;

            for(auto &d : dirs) {
                int nx = x + d.first;
                int ny = y + d.second;

                if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                int newHealth = h - grid[nx][ny];

                if(newHealth <= 0)
                    continue;

                if(newHealth > best[nx][ny]) {
                    best[nx][ny] = newHealth;
                    q.push({{nx, ny}, newHealth});
                }
            }
        }

        return false;
    }
};
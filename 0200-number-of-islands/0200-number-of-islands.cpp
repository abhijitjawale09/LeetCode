class Solution {
public:
    vector<pair<int ,int>> dirs = {{0,1} , {1, 0} , {-1 , 0} , {0,-1}};
    int n, m;
    void dfs(vector<vector<char>>& grid , int i , int j) {
        if(i < 0 || j < 0 || i > n - 1 || j > m - 1 || grid[i][j] != '1') {
            return;
        }

        if(grid[i][j] == '1') {
            grid[i][j] = -1;

            for(auto &dir : dirs) {
                int i_ = i + dir.first;
                int j_ = j + dir.second;
                dfs(grid , i_ , j_);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid , i , j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
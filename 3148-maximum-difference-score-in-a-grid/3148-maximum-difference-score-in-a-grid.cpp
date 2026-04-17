class Solution {
public:
    int n , m;
    int t[1001][1001];
    vector<vector<int>> dirs = {{0 ,1} , {1 , 0}};
    int solve(vector<vector<int>>& grid , int i , int j) {
        if(i >= n || j >= m) {
            return INT_MIN;
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }
        int best = INT_MIN;

        for(int k = 0; k < 2; k++) {
            int i_ = i + dirs[k][0];
            int j_ = j + dirs[k][1];

            if(i_ < n && j_ < m) {
                int diff = grid[i_][j_] - grid[i][j];

                int next = solve(grid, i_, j_);

                best = max(best , diff + max(0 , next));
            }
        }

        return t[i][j] = best;
    }
    int maxScore(vector<vector<int>>& grid) {
        n = grid.size() , m = grid[0].size();
        memset(t , -1 , sizeof(t));

        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans , solve(grid , i , j));
            }
        }
        return ans;
    }
};
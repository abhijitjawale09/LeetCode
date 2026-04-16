class Solution {
public:
    const int MOD = 1000000007;
    int n , m, K;
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>>& grid , int i , int j , int rem) {
        if(i >= n || j >= m || i < 0 || j < 0) {
            return 0;  
        }

        rem = (rem + grid[i][j]) % K;

        if(i == n -1 && j == m - 1) {
            return rem == 0;
        }

        if(dp[i][j][rem] != -1) {
            return dp[i][j][rem];
        }
        int right = 0 , down = 0;

        right = solve(grid, i + 1 , j , rem);
        down = solve(grid , i , j + 1, rem);

        return dp[i][j][rem] = (right + down) % MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        K = k;

        dp = vector<vector<vector<int>>>(n,vector<vector<int>>(m,vector<int>(K, -1)));
        return solve(grid , 0 , 0 , 0);
    }
};
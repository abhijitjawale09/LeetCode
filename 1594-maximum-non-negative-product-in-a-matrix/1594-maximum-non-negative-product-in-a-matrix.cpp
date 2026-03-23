class Solution {
public:   
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); 

        const long long MOD = 1e9 + 7;

        vector<vector<long long>> mi(n , vector<long long>(m , 0));
        vector<vector<long long>> mx(n , vector<long long>(m , 0));

        mi[0][0] = mx[0][0] = grid[0][0];

        for(int i = 1; i < m; i++) {
            mx[0][i] = mi[0][i] =  mx[0][i-1] * grid[0][i];
        }

        for(int i = 1; i < n; i++) {
            mx[i][0] = mi[i][0] =  mx[i-1][0] * grid[i][0];
        }


        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                long long x = grid[i][j];

                long long a = mx[i-1][j] * x;
                long long b = mi[i-1][j] * x;
                long long c = mx[i][j-1] * x;
                long long d = mi[i][j-1] * x;

                mx[i][j] = max({a , b, c , d});
                mi[i][j] = min({a , b , c ,d});
            }
        }

        long long ans = mx[n-1][m-1];

        if(ans < 0) return -1;
        return ans % MOD;
    }
};
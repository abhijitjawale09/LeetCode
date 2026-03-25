class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        long long totalsum = 0;

        for(int i = 0; i < n;i++) {
            for(int j = 0; j < m; j++)  {
                totalsum += grid[i][j];
            }
        }

        if (totalsum % 2) return false;

        long long curr = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < m ; j++) {
                curr += grid[i][j];
            }
            if(totalsum - curr == curr) {
                return true;
            }
        }  

        curr = 0;
        for(int i = 0; i < m-1; i++){
            for(int j = 0; j < n; j++) {
                curr += grid[j][i];
            }
            if(totalsum - curr == curr) {
                return true;
            }
        }    
        return false;
    }
};
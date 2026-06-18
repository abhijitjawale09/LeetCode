class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int res = 0;
        for(int i = 0; i < n; i++) {
            int low = 0 , high = m -1;
            int point = m;

            while(low <= high) {
                int mid = (low + high) / 2;

                if(grid[i][mid] < 0) {
                    high  = mid - 1;
                    point =  mid;
                }else {
                   low = mid + 1;
                }
            }
            res += m - point;
        }
        return res;
    }
};
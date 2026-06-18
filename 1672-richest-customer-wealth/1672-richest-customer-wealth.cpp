class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        int m = accounts[0].size();

        int maxsum = INT_MIN;
        for(int i = 0; i < n; i ++) {
            int currsum = 0;
            for(int j = 0; j < m; j++) {
                currsum += accounts[i][j];
            }
            maxsum = max(maxsum, currsum);
        }
        return maxsum;
    }
};
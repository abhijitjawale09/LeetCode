class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int m = banned.size();
        sort(banned.begin() , banned.end());
        int idx = 0,  cnt = 0;
        
        for(int i = 1; i <= n && maxSum >= 0; i++) {
            if(idx < m && banned[idx] == i) {
                while(idx < m && banned[idx] == i) {
                    idx++;
                }
            }else {
                maxSum -= i;
                if(maxSum >= 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
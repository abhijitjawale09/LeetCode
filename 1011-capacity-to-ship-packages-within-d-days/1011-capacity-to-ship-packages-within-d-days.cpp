class Solution {
public:
    int n;
    bool solve(int mid ,vector<int>& weights, int days ) {
        int count = 1 , sum = 0;
        for(int i = 0; i < n ; i++) {
            sum += weights[i];
            if(sum > mid) {
                count++;
                sum = weights[i];
            }
        }
        if(count <= days) {
            return  true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        n = weights.size();
        int maxwi = 0 , maxele = INT_MIN;
        for(int i = 0; i < n; i++) {
            maxwi += weights[i];
            maxele = max(maxele , weights[i]);
        }
        int res;
        while(maxele <= maxwi) {
            int mid = (maxele + maxwi)/2;  
            if(solve(mid , weights , days)) {
                res = mid;
                maxwi = mid - 1;
            }else{
                maxele = mid + 1;
            }
        }
        return res;
    }
};
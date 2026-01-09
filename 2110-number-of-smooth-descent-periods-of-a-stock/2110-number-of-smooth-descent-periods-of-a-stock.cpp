class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        
        long long  count = 1 , temp = 1;;
        for(int i = 1; i < n; i++) {
            if(prices[i] == prices[i-1] - 1) {
                temp++;
            }else{
                temp = 1;
            }
            count += temp;
        }
        return count;
    }
};
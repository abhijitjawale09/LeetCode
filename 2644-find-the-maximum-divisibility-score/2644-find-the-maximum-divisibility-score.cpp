class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {

        int n = nums.size();    
        int res = INT_MIN;
        int val = -1;
        for(int i = 0; i < divisors.size(); i++) {
            int currdiv = 0;
            for(int j = n-1; j >= 0; j--) {
                if(nums[j] % divisors[i] == 0) {
                    currdiv++;
                }
            } 

            if(res < currdiv) {
                res = currdiv;
                val = divisors[i];
            }
            else if(res == currdiv) {
                val = min(val , divisors[i]);
            }
        }

        return val;
    }
};
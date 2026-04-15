class Solution {
public:
    int n;
    int t[201][20001];
    bool solve(vector<int>& nums, int idx, int totalsum) {

        if(totalsum == 0) {
            return true;
        } 

        
        if(idx >= n || totalsum < 0) {
            return false;
        }
        if(t[idx][totalsum] != -1) {
            return t[idx][totalsum];
        }
        bool take = solve(nums , idx + 1 , totalsum - nums[idx]);
        bool skip = solve(nums , idx + 1, totalsum);

        return t[idx][totalsum] =take || skip;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        memset(t , -1 ,sizeof(t));
        int totalsum = accumulate(nums.begin() , nums.end() , 0);

        if(totalsum % 2 == 1)  {
            return false;
        }
        return solve(nums , 0 , totalsum/2);
    }
};
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        int presum = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 0) {
                presum += nums[i];
            }
        }

        vector<int> res(m);
        for(int i = 0; i < m ; i++) {
            int a = queries[i][0];
            int b = queries[i][1];

            if(nums[b] % 2 == 0) {
                presum -= nums[b];
            }
            nums[b] += a;
            if(nums[b] % 2 == 0) {
                presum += nums[b];
            }
            res[i] = presum; 
        }   
        return res;
    }
};
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;

        int i = 0;
        while(i < n) {
            long long zero = 0;
            while(i < n && nums[i] == 0) {
                zero++;
                i++;
            }
            count += ((zero + 1) *zero)/2;
            i++;
        }
        return count;
    }
};
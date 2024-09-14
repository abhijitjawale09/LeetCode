class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxx = *max_element(nums.begin() , nums.end());
        int count = 0;
        for(int i = 0; i < nums.size() ; i++) {
            if(nums[i] == maxx) {
            int temp = 0;
                while(i < nums.size() && nums[i] == maxx ) {
                    temp++;
                    i++;
                }
                count = max(count ,temp);
            }
        }
        return count;
    }
};
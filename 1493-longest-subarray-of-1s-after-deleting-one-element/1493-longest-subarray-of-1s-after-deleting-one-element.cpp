class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxone = 0, prevone = 0, currone = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                currone++;
            } else {
                maxone = max(maxone, prevone + currone);
                prevone = currone;  
                currone = 0;
            }
        }
        maxone = max(maxone, prevone + currone);
        if (maxone == n) maxone--;

        return maxone;
    }
};

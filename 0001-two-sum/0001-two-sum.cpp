class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int , int> mp;
        for(int i = 0; i < nums.size(); i++) {
            int constr = target - nums[i];
            if(mp.find(constr) != mp.end()) {
                return {mp[constr] , i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
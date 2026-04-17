class Solution {
public:
    int reverses(int num) {
        int temp = num;
        int ans = 0;
        while(temp % 10 == 0) {
            temp = temp/10;
        }
        while(temp != 0) {
            ans = ans * 10 + temp % 10;
            temp /= 10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;


        unordered_map<int , int> mp;
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            int rev = reverses(num);

            if(mp.count(nums[i])) {
                res = min(res , abs(i - mp[num]));
            }
            mp[rev] = i;
        }
        return (res == INT_MAX) ? -1 : res;
    }
};
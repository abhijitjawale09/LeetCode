class Solution {
public:
    int n;
    vector<vector<int>> res;
    void solve(vector<int>& nums , vector<int>& curr, vector<bool>& used) {
        if(curr.size() == n){
            res.push_back(curr);
            return;
        }

        for(int i = 0; i < n; i++) {

            if(used[i]) continue;

            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

            used[i] = true;
            curr.push_back(nums[i]);
            solve(nums , curr , used);
            curr.pop_back();

            used[i] = false;
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
         sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<bool> used(n , false);
        solve(nums , temp , used);
        return res;
    }
};
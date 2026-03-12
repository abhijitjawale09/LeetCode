class Solution {
public:
    vector<vector<int>> res;
    void solve(int n , int k, int idx , vector<int>& curr) {

        // if(idx >= n) {
        //     return;
        // }
        if(curr.size() == k) {
            res.push_back(curr);
            // curr.pop_back();
            return ;
        }
        
        for(int i = idx; i <= n; i++) {
            curr.push_back(i);
            solve(n, k, i + 1,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        solve(n , k, 1, curr);
        return res;
    }
};
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();

        unordered_map<int , int> dp;

        int ans = 1;
        for(int i = 0; i < n; i++) {
            int num = arr[i];
            if(dp.find(num - difference) != dp.end()) {
                dp[num] = dp[num-difference] + 1;
            }else{
                dp[num] = 1;
            }

            ans = max(ans , dp[num]);
        }
        return ans;
    }
};


// class Solution {
// public:
//     int n;
    
//     vector<vector<int>> t;
//     int solve(vector<int>& arr , int diff, int idx , int prev) {
//         if(idx >= n) {
//             return 0;
//         }

//         if(t[idx][prev + 1] != -1) {
//             return t[idx][prev + 1];
//         }

//         int take = 0 , skip = 0;
//         if(prev == -1 || (arr[idx] - arr[prev]) == diff) {
//             take = 1 + solve(arr, diff , idx + 1, idx);
//         }
//         skip = solve(arr , diff , idx + 1 , prev);

//         return t[idx][prev + 1] = max(take , skip);
//     }
//     int longestSubsequence(vector<int>& arr, int difference) {
//         n = arr.size();
//         t.resize(n , vector<int>(n + 1, -1));
//         return solve(arr ,difference , 0 , -1);
//     }
// };
class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int nextIndex(vector<vector<int>>& events, int i) {
        int l = i + 1, r = n - 1;
        int ans = n;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (events[mid][0] > events[i][1]) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int solve(vector<vector<int>>& events, int i, int k) {
        if (i == n || k == 0) return 0;

        if (dp[i][k] != -1) return dp[i][k];

        // skip
        int skip = solve(events, i + 1, k);

        // take
        int next = nextIndex(events, i);
        int take = events[i][2] + solve(events, next, k - 1);

        return dp[i][k] = max(take, skip);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();

        sort(events.begin(), events.end()); // sort by start time

        dp.resize(n, vector<int>(k + 1, -1));

        return solve(events, 0, k);
    }
};
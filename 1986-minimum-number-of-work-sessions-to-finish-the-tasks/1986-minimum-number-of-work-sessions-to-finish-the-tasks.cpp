class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        int N = 1 << n;

        vector<pair<int,int>> dp(N, {n + 1, 0});
        dp[0] = {1, 0};

        for(int mask = 1; mask < N; mask++) {
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    auto prev = dp[mask ^ (1 << i)];

                    int sessions = prev.first;
                    int time = prev.second;

                    if(time + tasks[i] <= sessionTime) {
                        time += tasks[i];
                    } else {
                        sessions++;
                        time = tasks[i];
                    }

                    dp[mask] = min(dp[mask], {sessions, time});
                }
            }
        }

        return dp[N - 1].first;
    }
};
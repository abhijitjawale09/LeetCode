class Solution {
public:
    int ans = INT_MAX;

    unordered_map<string, int> memo;

    void solve(int idx,
               vector<int>& tasks,
               vector<int>& sessions,
               int sessionTime) {

        if(idx == tasks.size()) {
            ans = min(ans, (int)sessions.size());
            return;
        }

        // Create state string
        string key = to_string(idx) + "|";
        for(int x : sessions)
            key += to_string(x) + ",";

        // Memo check
        if(memo.count(key) &&
           memo[key] <= sessions.size())
            return;

        memo[key] = sessions.size();

        // Try existing sessions
        for(int i = 0; i < sessions.size(); i++) {

            if(sessions[i] + tasks[idx] <= sessionTime) {

                sessions[i] += tasks[idx];

                solve(idx + 1,
                      tasks,
                      sessions,
                      sessionTime);

                sessions[i] -= tasks[idx];
            }
        }

        // Create new session
        sessions.push_back(tasks[idx]);

        solve(idx + 1,
              tasks,
              sessions,
              sessionTime);

        sessions.pop_back();
    }

    int minSessions(vector<int>& tasks,
                    int sessionTime) {

        sort(tasks.rbegin(), tasks.rend());

        vector<int> sessions;

        solve(0, tasks, sessions, sessionTime);

        return ans;
    }
};
class Solution {
public:
    int res = INT_MIN;
    int m , N;
    void solve(vector<vector<int>>& req , int idx ,int count, vector<int>& track){
        if(idx >= m) {
            bool allzero = true;
            for(int &x : track) {
                if(x != 0) {
                    allzero = false;
                    break;
                }
            }
            if(allzero == true) {
                res = max(res , count);
            }
            return;
        }

         solve(req, idx + 1, count, track);

        // TAKE
        int from = req[idx][0];
        int to = req[idx][1];

        track[from]--;
        track[to]++;

        solve(req, idx + 1, count + 1, track);

        // BACKTRACK
        track[from]++;
        track[to]--;
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        m = requests.size();
        N = n;
        vector<int> track(n , 0);
        solve(requests , 0 , 0, track);
        return res;
    }
};
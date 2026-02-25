class Solution {
public:
    int n;
    const int MOD = 1e9 + 7;
    int t[101][201];
    int solve(vector<int>& locations ,int idx ,int ed , int fuel) {
        if(fuel < 0) {
            return 0;
        }
        if(t[idx][fuel] != -1) {
            return t[idx][fuel];
        }
        int ans = 0;
        if(idx == ed) {
            ans += 1;
        }
        for(int j = 0; j < n; j++) {
            if(j != idx) {
                int rem = fuel - abs(locations[j] - locations[idx]);
                ans = (ans + solve(locations, j , ed , rem))%MOD;
            }
        }
        return t[idx][fuel] = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();
        memset(t ,-1 , sizeof(t));
        return solve(locations , start,finish , fuel);
    }
};
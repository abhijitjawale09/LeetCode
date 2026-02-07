class Solution {
public:
    int n;
    int memo[50001];
    int getnextindex(vector<vector<int>>& arr ,int l , int target) {
        int r = n-1;
        int res = n;

        while(l <= r) {
            int mid = l + (r - l)/2;

            if(arr[mid][0] >= target) {
                res = mid;
                r = mid -1;
            }else{
                l = mid + 1;

            }
        }
        return res;
    }
    int solve(vector<vector<int>>& arr , int i) {
        if(i >= n) {
            return 0;
        }

        if(memo[i] != -1) return memo[i];
        int next = getnextindex(arr , i + 1, arr[i][1]);
        int take = arr[i][2] + solve(arr , next);
        int not_take = solve(arr , i + 1);

          return memo[i] = max(take , not_take); 
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        vector<vector<int>> arr;
        memset(memo , -1 , sizeof(memo));
        for(int i = 0; i < n; i++) {
            int st = startTime[i];
            int ed = endTime[i];
            int pr = profit[i];

            arr.push_back({st , ed , pr});
        }

        auto comp = [&](auto& vec1 ,auto& vec2) {
            return vec1[0] < vec2[0];
        };
        sort(arr.begin() , arr.end() , comp);

        return solve(arr , 0);
    }
};
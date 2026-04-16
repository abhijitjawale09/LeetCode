class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        int n = nums.size();
        vector<int> res(queries.size(), -1);

        unordered_map<int , vector<int>> mp;

        // store indices
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for(int i = 0; i < queries.size(); i++) {

            int idx = queries[i];
            int num = nums[idx];

            vector<int> &vec = mp[num];

            if(vec.size() == 1) {
                res[i] = -1;
                continue;
            }

            auto it = lower_bound(vec.begin(), vec.end(), idx);

            int pos = it - vec.begin();

            int dist = INT_MAX;

            if(pos > 0) {
                int d = idx - vec[pos - 1];
                dist = min(dist, d);
            }
            if(pos < vec.size() - 1) {
                int d = vec[pos + 1] - idx;
                dist = min(dist, d);
            }
            int first = vec[0];
            int d1 = n - abs(idx - first);
            dist = min(dist, d1);
            int last = vec.back();
            int d2 = n - abs(idx - last);
            dist = min(dist, d2);

            res[i] = dist;
        }

        return res;
    }
};
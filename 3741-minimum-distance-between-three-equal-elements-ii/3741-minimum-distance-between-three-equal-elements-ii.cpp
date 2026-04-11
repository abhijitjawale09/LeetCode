class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , vector<int>> mp;

        int mindist = INT_MAX;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            if(mp[nums[i]].size() >= 3) {
                auto &v = mp[nums[i]];

                int sz = v.size();

                int i = v[sz - 3];
                int j = v[sz - 2];
                int k = v[sz  - 1];

                mindist = min(mindist , abs(i - j) + abs(j - k) + abs(k - i));
            }
        }


        return mindist == INT_MAX ? -1 : mindist;
    }
};
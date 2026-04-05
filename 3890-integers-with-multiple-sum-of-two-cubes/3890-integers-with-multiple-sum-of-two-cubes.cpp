class Solution {
public:
    vector<int> findGoodIntegers(int n) {
       map<long long ,int> mp;
       vector<long long > c;
       for(int i = 1 ; i * i * i <= n; i++)  {
            c.push_back(i*i*i);
       }

        for(int i = 0; i < (int)c.size(); i++) {
            for(int j = i; j < (int)c.size(); j++) {
                if(c[i] + c[j] > n) break;
                mp[c[i] + c[j]]++;
            }
        }

        vector<int> ans;
        for(auto &x : mp) {
            if(x.second >= 2) {
                ans.push_back((int)x.first);
            }
        }
        return ans;
    }
};
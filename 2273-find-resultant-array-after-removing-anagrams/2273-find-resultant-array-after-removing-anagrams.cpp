class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        if (words.empty()) return {};
        int n = words.size();
        vector<int> freq(26 , 0);
        string s = words[0];
        vector<string> res;
        for(int k = 0; k < s.size(); k++) {
            freq[s[k] - 'a']++;
        }
        res.push_back(s);
        for(int i = 1; i < n; i++) {
            string a = words[i];
            vector<int> tmp(26 , 0);
            for(int j = 0; j < a.size(); j++) {
                tmp[a[j] - 'a']++;
            }

            if(freq != tmp) {
                res.push_back(a);
                freq = tmp;
            }
        }
        return  res;
    }
};
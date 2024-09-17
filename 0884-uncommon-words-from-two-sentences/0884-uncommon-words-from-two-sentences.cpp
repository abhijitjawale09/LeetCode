class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
       string ss = s1 + " " + s2;
       unordered_map<string , int> mp;
       
      stringstream iss(ss);
       string word;
        while (iss >> word) {
            mp[word]++;
        }
        
       vector<string> ans;
       for(auto &val : mp) {
            if(val.second == 1) {
                ans.push_back(val.first);
            }
        }

       return ans;
    }
}; 
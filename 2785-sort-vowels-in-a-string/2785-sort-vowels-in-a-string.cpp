class Solution {
public:
    string sortVowels(string s) {
        vector<char> vi;
        int n = s.size();


        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        for(int i = 0; i < n; i++) {
            if(vowels.find(s[i]) != vowels.end()) {
                vi.push_back(s[i]);
            }
        }

        sort(vi.begin() , vi.end());

        int j = 0;
        for(int i = 0; i < n; i++) {
            if(vowels.find(s[i]) != vowels.end()) {
                s[i] = vi[j];
                j++;
            }
        }

        return s;
    }
};
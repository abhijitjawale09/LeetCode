class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();


        int res = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(words[(startIndex + i) % n] == target || words[(startIndex - i + n) % n] == target) {
                return i;
            }
        }   
        return res == INT_MAX ? -1 : res;
    }
};
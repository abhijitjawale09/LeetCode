class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& v) {
        int n = v.size();
        
        sort(v.begin() , v.end() , [](const vector<int>& a , const vector<int>& b) {
            if(a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        int cnt = 0;

        int left = -1 , right = -1;
        for(auto it : v) {
            if(left < it[0] && right < it[1]) {
                left = it[0];
                cnt++;
            }
            right = max(right , it[1]);
        }
        return cnt;
    }
};
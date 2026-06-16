class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inter) {
        int n = inter.size();
        int m = inter[0].size();
    
        sort(inter.begin() , inter.end() , [](const vector<int>& a , const vector<int>& b) {
            if(a[0] == b[0]) {
              return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        int a = inter[0][0];
        int b = inter[0][1];

        int cnt = 0;
        for(int i = 1; i < n ; i++) {
            int c = inter[i][0];
            int d = inter[i][1];

            if(a <= c && b >= d) {
                cnt++;
            }else {
                a = c;
                b= d;
            }
        }
        return n - cnt;
    }
};
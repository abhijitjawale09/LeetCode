class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxdist = 0;
        int max1 = -1;
        int c1 = colors[0] , c2 = -1 , i1 = 0 , i2 = -1;
        for(int i = n-1; i >= 0; i--) {
            if(colors[i] != c1){
                max1 = i;
                break;
            }
        }

        c1 = colors[n-1] , i1 = n-1;
        for(int i = 0; i < n; i++) {
            if(colors[i] != c1) {
                return max(max1 , i1 - i);
            }
        }
        return -1;
    }
};
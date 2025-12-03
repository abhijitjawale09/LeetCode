class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        vector<int> lhs(n) , rhs(n);
        rhs[0] = height[0];
        for(int i = 1; i < n; i++){
            rhs[i] = max( rhs[i-1], height[i]);
        }
        lhs[n-1] = height[n-1];
        for(int i = n - 2; i >= 0; i--) {
            lhs[i] = max(lhs[i+1] , height[i]);
        }

        for(int i = 0; i < n; i++) {
            total += min(rhs[i] , lhs[i]) - height[i];
        }
        return total;
    }
};
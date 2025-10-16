class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec(n, vector<int> (n));

        int count = 1;
        int top = 0 , bottom = n -1 , left = 0, right = n - 1;
        while(top <= bottom &&  left <= right) {
            for(int i = left; i <= right; i++) {
                vec[top][i] = count++;
            }
            top++;

            for(int i = top;i <=  bottom ; i++) {
                vec[i][right] = count++;
            }
            right--;
            if(top <= bottom) {
                for(int i = right;i >= left; i--) {
                    vec[bottom][i] = count++;
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    vec[i][left] = count++;
                left++;
            }
        }
        return vec;
    }
};
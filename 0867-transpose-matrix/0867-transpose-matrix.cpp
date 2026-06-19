class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> res(m , vector<int>(n));
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
               res[j][i] = matrix[i][j];
            }
        }

        // for(int i = 0; i < matrix.size(); i++) {
        //     reverse(matrix[i].begin(), matrix[i].end());
        // }
        return res;
    }
};
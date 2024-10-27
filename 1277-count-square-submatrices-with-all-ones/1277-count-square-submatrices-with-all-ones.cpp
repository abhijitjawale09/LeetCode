class Solution {
public:
    // int n , m ;
    // int solve(int i , int j , vector<vector<int>>& matrix , vector<vector<int>>& t) {
    //     if(i >= m || j >= m ) {
    //         return 0;
    //     }
    //     if(matrix[i][j] == 0) {
    //         return 0;
    //     }
    //     if(t[i][j] != -1) {
    //         return t[i][j];
    //     }
    //     int right = solve(i , j + 1 , matrix , t);
    //     int diag = solve(i + 1 , j + 1 , matrix , t);
    //     int below = solve(i + 1 , j , matrix , t);

    //     return t[i][j] =  1 + min({right , diag , below});

    // }
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int count = 0;
        vector<vector<int>> t(n , vector<int>(m , 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0 ; j < m; j++) {
                if(i == 0 || j == 0) {
                    t[i][j] = matrix[i][j];

                }
                else if(matrix[i][j] == 1) {
                    t[i][j] = 1 + min({t[i - 1][j] , t[i -1][j -1], t[i][j -1]});
                }
                count += t[i][j];

            }
        }
        return count;
    }
};
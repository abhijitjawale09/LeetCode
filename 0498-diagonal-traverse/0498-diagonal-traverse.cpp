class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> ans;
        int i = 0;
        int j = 0;
        bool upward = true;
        while(ans.size() < n * m) {
             ans.push_back(mat[i][j]);

             if(upward) {
                if(j == m-1) {
                    i++;
                    upward = false;
                }else if(i == 0) {
                    j++;
                    upward = false;
                }else{
                    i-- , j++;

                }
            }else{
                if(i == n - 1){
                    j++;
                    upward = true;
                }else if(j == 0){
                    i++;
                    upward = true;
                }else{
                    i++;
                    j--;
                }
             }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
//         int n = mat.size();
//         int m = mat[0].size();

//         vector<int> res;

//         int i = 0, j = 0;
//         for(int s = 0; s <= n + m -2; s++) {
//             for(int x = 0; x <= s; x++) {
//                 int i = x;
//                 int j = s - i;

//                 if(s%2 == 0) {
//                     swap(i , j);
//                 }
//                 if(i >= n || j >= m) {
//                     continue;
//                 }

//                 res.push_back(mat[i][j]);
//             }
//         }
//         return  res;
//     }
// };
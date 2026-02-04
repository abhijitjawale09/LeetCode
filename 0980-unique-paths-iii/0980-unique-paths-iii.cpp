class Solution {
public:
    int n , m ,total = 0;
    vector<vector<int>> dirs = {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}};
    int dfs(vector<vector<int>>& grid , int i , int j , int count) {
        if(i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == -1) {
            return 0;
        }
        if(grid[i][j] == 2) {
            return (count == total)? 1 : 0;
        }

        int temp = grid[i][j];
        grid[i][j] = -1;

        int way = 0;
        for(auto &dir : dirs) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            way += dfs(grid , i_ , j_ , count + 1);
        }
        grid[i][j] = temp;
        return way;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int sx , sy;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != -1) total++;
                if(grid[i][j] == 1) {
                   sx = i , sy = j;
                }
            }
        }
        return dfs(grid , sx , sy , 1);
    }
};
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();

        int maxdai = 0 , maxArea = 0;
        for(auto it : dimensions) {
            int ff = it[0];
            int ss  = it[1];

            int dia = ff * ff + ss * ss;
            if(dia > maxdai || (dia == maxdai && ff * ss > maxArea)){
                maxdai= dia;
                maxArea = ff*ss;
            }
        }
        return maxArea;
    }
};
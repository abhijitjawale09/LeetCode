class Solution {
public:

    vector<pair<int , int>> vec;
    int dp[301][27][27];
    int n;
    int cal(int a , int b) {
        if(a == 26 ) return 0;
        return abs(vec[a].first - vec[b].first) + abs(vec[a].second - vec[b].second); 
    }
    int solve(string &word , int idx , int left , int right) {
        if(idx >= n) {
            return 0;
        }

        if(dp[idx][left][right] != -1) {
            return dp[idx][left][right];
        }
        int leftfig = 0 , rightfig = 0;

        int curr = word[idx] - 'A';
        leftfig =  cal(left ,curr) + solve(word , idx + 1 , curr , right);

        rightfig = cal(right , curr) + solve(word , idx + 1 , left , curr);


        return dp[idx][left][right] = min(leftfig , rightfig);

    }
    int minimumDistance(string word) {
        n = word.size();
        vec.resize(26);
        memset(dp , -1 , sizeof(dp));
        for(int i = 0; i < 26; i++) {
            vec[i] = {i/6 , i % 6};
        }
        return solve(word , 0 , 26 , 26 );
    }
};
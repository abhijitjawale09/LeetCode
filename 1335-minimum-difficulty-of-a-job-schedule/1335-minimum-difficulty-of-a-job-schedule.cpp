class Solution {
public:
    int t[301][11];
    int solve(vector<int> &jd , int n ,int i , int d) {

        if(d == 1) {
           int maxD = 0;
            for(int k = i; k < n; k++) {
                maxD = max(maxD , jd[k]);
            }
            return maxD;
        }

        if(t[i][d] != -1 ) {
            return t[i][d];
        }
        int maxD = 0;
        int finalres = INT_MAX;

        for(int j = i; j <= n -d; j++) {
            maxD = max(maxD , jd[j]);

            int result = maxD + solve(jd , n , j+ 1, d - 1);

            finalres = min(finalres , result);
        }

        return t[i][d] = finalres;
    }
    int minDifficulty(vector<int>& job, int d) {
        int n = job.size();

        if(n < d) {
            return -1;
        }   

        memset(t , -1 ,sizeof(t));
        return solve(job, n , 0, d);
    }
};
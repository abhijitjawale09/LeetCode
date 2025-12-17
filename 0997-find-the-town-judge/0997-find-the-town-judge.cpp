class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int size = trust.size();
        vector<int> indegree(n+1, 0);
        vector<int> outdegree(n+1, 0);

        for(int i = 0; i < size; i++) {
            int a = trust[i][0];
            int b = trust[i][1];

           outdegree[a]++;
           indegree[b]++;
        }
        for(int i = 1; i <= n; i++) {
            if(indegree[i] == n -1 && outdegree[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
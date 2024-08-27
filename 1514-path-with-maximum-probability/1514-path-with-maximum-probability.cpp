class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> maxProb(n , 0.0);
        maxProb[start_node] = 1.0;

        for(int i = 0; i < n - 1; i++) {
            bool update = false;
            for(int j = 0; j < edges.size(); j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                double prob = succProb[j];

                if(maxProb[u] * prob > maxProb[v]) {
                    maxProb[v] = maxProb[u] * prob;
                    update = true;
                }
                 if (maxProb[v] * prob > maxProb[u]) {
                    maxProb[u] = maxProb[v] * prob;
                    update = true;
                }

            }
            if(!update) break;
        }

        return maxProb[end_node];
    }
};
class Solution {
public:
    typedef pair<double , int> P;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int , vector<pair<int ,double>>> adj;

        vector<double> res(n , 0);

        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1] , (double)succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0] ,(double)succProb[i]});
        }

        priority_queue<P> pq;
        res[start_node] = 1;
        pq.push({1.0 , start_node});


        while(!pq.empty()) {
            int currnode = pq.top().second;
            double currprob = pq.top().first;
            pq.pop();
            for(auto &temp : adj[currnode]) {
                double adjprob = temp.second;
                int adjnode = temp.first;

                if(res[adjnode] < currprob*adjprob ){
                    res[adjnode] = currprob*adjprob;
                    pq.push({res[adjnode] , adjnode});
                }
            }
        }

        return res[end_node];
    }
};
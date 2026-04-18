class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int mn = 0;
        vector<int> vis(n);
        vector<vector<vector<int>>> invg(n);

        for(auto &ed : edges) {
            invg[ed[1]].push_back({ ed[2] , ed[0]});
        }

        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        pq.push({0 , 0});

        while(pq.size()) {
            auto node = pq.top()[1] , w = pq.top()[0];;
            pq.pop();

            if(vis[node]) continue;

            vis[node] = 1;
            mn = max(mn , w);

            for(auto i : invg[node]) {
                if(!vis[i[1]]) {
                    pq.push(i);
                }
            }
        }
        for(auto i : vis) {
            if(i == 0) {
                return -1;
            }
        }
        return mn;
    }
};
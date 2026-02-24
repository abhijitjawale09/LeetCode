class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> res(n);
        sort(deck.begin() , deck.end());
        queue<int> q;

        for(int i = 0; i < n; i++) {
            q.push(i);
        }

        for(int i = 0; i < n; i++) {
            int idx = q.front();
            q.pop();

            res[idx] = deck[i];

            if(!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        return res;
    }
};
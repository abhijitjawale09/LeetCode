class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);

        for (auto &t : trips) {
            int passengers = t[0];
            int start = t[1];
            int end = t[2];

            diff[start] += passengers;   
            diff[end] -= passengers;     
        }

        int curr = 0;
        for (int x : diff) {
            curr += x;
            if (curr > capacity) return false;
        }

        return true;
    }
};

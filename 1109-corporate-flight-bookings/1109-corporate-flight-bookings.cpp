class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n, 0);
        for(int i = 0; i < bookings.size(); i++) {
            int u = bookings[i][0] - 1;
            int v = bookings[i][1] - 1;
            int seat = bookings[i][2];

            diff[u] += seat;
            if(v + 1 < n) {
                diff[v + 1] -= seat;
            }
        }

        for(int i = 1; i < n; i++) {
            diff[i]  = diff[i-1] + diff[i];
        }
        return diff;
    }
};
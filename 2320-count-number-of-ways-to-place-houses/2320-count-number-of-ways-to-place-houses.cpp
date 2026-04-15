class Solution {
public:
    const int MOD = 1000000007;

    int countHousePlacements(int n) {
        if(n == 1) {
            return 4;
        }

        if(n == 2) {
            return 9;
        }

        int prev_prev = 2;
        int prev = 3;

        for(int i = 3; i <= n; i++) {
            int curr = (prev + prev_prev) % MOD;
            prev_prev = prev;
            prev = curr;
        }

        return (1LL * prev * prev) % MOD;
    }
};
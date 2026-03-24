class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int size = m * n;
        const int MOD = 12345;

        vector<long long> pref(size, 1), suff(size, 1);
        for (int i = 1; i < size; i++) {
            int r = (i - 1) / n;
            int c = (i - 1) % n;
            pref[i] = (pref[i - 1] * grid[r][c]) % MOD;
        }

        for (int i = size - 2; i >= 0; i--) {
            int r = (i + 1) / n;
            int c = (i + 1) % n;
            suff[i] = (suff[i + 1] * grid[r][c]) % MOD;
        }

        vector<vector<int>> res(m, vector<int>(n));

        for (int i = 0; i < size; i++) {
            int r = i / n;
            int c = i % n;

            long long prod = (pref[i] * suff[i]) % MOD;
            res[r][c] = prod;
        }

        return res;
    }
};
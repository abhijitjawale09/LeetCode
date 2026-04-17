class Solution {
public:
    int maxTotalReward(vector<int>& r) {

        sort(r.begin(), r.end());

        // Remove duplicates
        r.erase(unique(r.begin(), r.end()), r.end());

        int n = r.size();

        bitset<50000> dp, mask;
        dp[0] = true;

        int maskid = 0;

        for (int i = 0; i < n; i++) {

            if (maskid < r[i]) {

                while (maskid < r[i]) {
                    mask[maskid++] = true;
                }

                dp |= (dp & mask) << r[i];
            }
        }

        int closestSum = r.back() - 1;

        while (!dp[closestSum]) {
            closestSum--;   // FIXED
        }

        return r.back() + closestSum;
    }
};
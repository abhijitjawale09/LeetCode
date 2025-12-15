class Solution {
public:
    bool canzero(vector<int> &count) {
        for (int i = 0; i < 128; i++) {
            if (count[i] > 0) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (m > n) return "";

        vector<int> count(128, 0);

        for (int i = 0; i < m; i++) {
            count[t[i]]++;
        }

        int i = 0, j = 0;
        int minlen = INT_MAX;
        int mi = -1;

        while (i < n) {
            count[s[i]]--;

            while (j <= i && canzero(count)) {
                if (i - j + 1 < minlen) {
                    minlen = i - j + 1;
                    mi = j;
                }
                count[s[j]]++;
                j++;
            }
            i++;
        }

        if (mi == -1) return "";
        return s.substr(mi, minlen);
    }
};

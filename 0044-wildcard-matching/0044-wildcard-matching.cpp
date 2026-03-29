class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        int i = 0, j = 0;
        int star = -1, match = 0;

        while (i < n) {
            if (j < m && (p[j] == '?' || s[i] == p[j])) {
                i++;
                j++;
            }
            else if (j < m && p[j] == '*') {
                star = j;
                match = i;
                j++;
            }
            else if (star != -1) {
                j = star + 1;
                match++;
                i = match;
            }
            else {
                return false;
            }
        }

        while (j < m && p[j] == '*') {
            j++;
        }

        return j == m;
    }
};
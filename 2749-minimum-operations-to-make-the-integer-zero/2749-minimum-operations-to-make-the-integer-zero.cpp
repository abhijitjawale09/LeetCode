#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeTheIntegerZero(long long num1, long long num2) {
        for (int k = 1; k <= 60; k++) {
            long long val = num1 - k * num2;
            if (val < 0) continue;
            int bits = __builtin_popcountll(val);
            if (bits <= k && k <= val) {
                return k;
            }
        }
        return -1;
    }
};

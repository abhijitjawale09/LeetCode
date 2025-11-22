const long long MOD = 1e9 + 7;
class Solution {
public:
    
    long long power(long long a , long long b ) {
        long long ans = 1;
        while(b > 0) {
            if(b & 1) ans = (ans * a) % MOD;
            a = (a * a ) % MOD;
            b >>= 1;
        }
        return ans;
    }
    int countAnagrams(string s) {
        long long result = 1;
        vector<long long> fact(100001) , invfact(100001);
        fact[0] = 1;
        for(int i = 1; i <= 100000; i++) {
            fact[i] = (fact[i-1] * i) % MOD;
        }
        invfact[100000] = power(fact[100000] , MOD - 2);
        for (int i = 99999; i >= 0; i--)
            invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;

        // long long fact = 1;
        string word = "";
        for(char c : s + " ") {
            if(c != ' ') {
                word += c;
            }else {
                vector<int> freq(26, 0);
                for(int i = 0; i < word.size(); i++) {
                    freq[word[i] - 'a']++; 
                }

                int n = word.size();
                long long ways = fact[n];

                for(int f : freq) {
                    if(f > 1) {
                        ways = ( ways* invfact[f]) % MOD;
                    }
                }

                result = (result*ways) % MOD;
                word = "";
            }
        }
        return result % MOD;
    }
};
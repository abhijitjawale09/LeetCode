class Solution {
public:
    int M =  1e9 + 7;
    int t[201][201][2];
    int solve(int onesleft , int zerosleft , bool lastwalaone , int limit) {
        if(onesleft == 0 && zerosleft == 0) {
            return 1;
        }

        if(t[onesleft][zerosleft][lastwalaone] != -1) {
            return t[onesleft][zerosleft][lastwalaone];
        }
        int res = 0;

        if(lastwalaone == true) {
            for(int len = 1; len <= min(zerosleft , limit); len++) {
                res = (res + solve(onesleft , zerosleft - len , false, limit)) % M;
            }
        }else {
            for(int len = 1; len <= min(onesleft , limit); len++) {
                res = (res + solve(onesleft - len , zerosleft, true, limit)) % M;
            }
        }
        return t[onesleft][zerosleft][lastwalaone] = res;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t , -1, sizeof(t));
        int startwithzero = solve(one , zero , false, limit);
        int startwithone = solve(one, zero , true , limit);
        return (startwithone  + startwithzero) % M;
    }
};
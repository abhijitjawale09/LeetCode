class Solution {
public:
    int getMaximumGenerated(int n) {
        
        if(n == 0) {
            return 0;
        }
        vector<int> arr(n+1 ,0);
        arr[0] = 0;
        arr[1] = 1;
        int res = 1;

        for(int i = 0; 2 * i <= n ; i++) {
            if(i*2 <= n) {
                arr[i*2] = arr[i];
            }
            res = max(res , arr[2 * i]);

            if(i* 2 + 1 <= n) {
                arr[i * 2 + 1] = arr[i] + arr[i + 1];
                res = max(res , arr[2 * i + 1]);
            }
        }

        return res;

    }
};
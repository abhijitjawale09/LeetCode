class Solution {
public:
    int n;
    bool solve(int mountainHeight, vector<int>& workerTimes , long long target) {
        long long total = 0;
        for(int i = 0; i < n; i++) {
            long long t = workerTimes[i];

            long double D = 1.0 + (8.0L * target) / t;
            long long k = (long long)((-1 + sqrtl(D)) / 2);

            total += k;

            if(total >= mountainHeight) return true;
        }

        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        n = workerTimes.size();
        long long second = LLONG_MAX , currsec = LLONG_MAX;
        long long md = *max_element(workerTimes.begin(), workerTimes.end());
        long long tmin = *min_element(workerTimes.begin(), workerTimes.end());
        long long st = 0;
        long long ed = (long long)tmin * mountainHeight * (mountainHeight + 1) / 2;

        while(st <= ed) {
            long long mid = st + (ed - st)/2;
            if(solve(mountainHeight , workerTimes , mid) == true){
                second = min(second , mid);
                ed = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        return second;
    }
};
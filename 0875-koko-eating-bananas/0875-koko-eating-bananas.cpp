class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int low = 1 ;
        int high = *max_element(piles.begin(), piles.end());
        while(low < high) {
            int mid = low + (high - low)/2; 

            long long  total = 0;
            for(int i = 0; i < n; i++) {
                total += (piles[i] + mid -1)/mid;
            }
            if(total <= h) {
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};
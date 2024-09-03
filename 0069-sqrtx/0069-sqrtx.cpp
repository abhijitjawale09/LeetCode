class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) {
            return x;
        }
        int low = 0;
        int high = x;
        long long mid = (low + high) / 2;

        while (low <= high)
        {           
            mid = (low + high) / 2;
            if ((mid*mid) < x)
                low = mid + 1;
            else if ((mid*mid) > x)
                high = mid - 1;
            else 
                return mid;             
        }
        return ((mid*mid) > x) ? (int(mid) - 1): int(mid);
    
    }
};
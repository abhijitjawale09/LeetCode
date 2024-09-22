class Solution {
public:
    // Helper function to count how many numbers exist between curr and next
    int Count(long curr, long next, int n) {
        int countnum = 0;
        while (curr <= n) {
            countnum += min(next, long(n + 1)) - curr;
            curr *= 10;
            next *= 10;
        }
        return countnum;
    }

    int findKthNumber(int n, int k) {
        long curr = 1;
        k -= 1; // We are already at the first number (1), so decrement k
        
        while (k > 0) {
            long count = Count(curr, curr + 1, n); // Count numbers in range [curr, curr+1)
            
            if (count <= k) {
                // If count is less than or equal to k, move to the next prefix
                curr++;
                k -= count;
            } else {
                // Otherwise, move to the next lexicographical level
                curr *= 10;
                k -= 1; // We move to the next number in lexicographical order, so decrement k
            }
        }
        return curr;
    }
};

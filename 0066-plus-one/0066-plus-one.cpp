class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for(int i = n - 1 ; i >=0 ; i--) {
            if(digits[i] != 9) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
        }

         vector<int> newDigits(digits.size() + 1, 0); // All elements initialized to 0
        newDigits[0] = 1;  // Set the first digit to 1
        return newDigits;
    }
};
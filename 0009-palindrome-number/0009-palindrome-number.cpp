class Solution {
public:
    bool isPalindrome(int x) {
        // string s = to_string(x);
        // int right = 0 , left = s.size() - 1;
        // while(right < left) {
        //     if(s[right] != s[left]){
        //         return false;
        //     }
        // right++;
        // left--;
        // }
        // return true;
         if (x < 0) {
        return false;
    }
    // Numbers ending in 0 that are not 0 are not palindromes
    if (x != 0 && x % 10 == 0) {
        return false;
    }

    int reversedHalf = 0;
    while (x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + x % 10;
        x /= 10;
    }

    // If the number is odd, we can get rid of the middle digit by reversedHalf/10
    return x == reversedHalf || x == reversedHalf / 10;
    }
};
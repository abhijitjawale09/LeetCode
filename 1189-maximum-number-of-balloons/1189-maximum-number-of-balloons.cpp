class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0 , a = 0 , l = 0 , n = 0 , o = 0;
        for(auto ch : text) {
            if(ch == 'a' ) {
                a++;
            }else if(ch == 'b' ) {
                b++;
            }else if(ch == 'l' ) {
                l++;
            }else if(ch == 'n' ) {
                n++;
            }else if(ch == 'o' ) {
                o++;
            }
        }
        return min({a , b, l/2 , n , o/2});
    }
};
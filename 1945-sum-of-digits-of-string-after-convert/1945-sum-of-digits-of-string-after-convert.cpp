class Solution {
public:
    int getLucky(string s, int k) {
        string in = "";

        for(int i = 0; i < s.size(); i++) {
            in += to_string(s[i] - 'a' + 1);
        }

        while(k > 0) {
            int temp = 0;
            for(char x : in) {
                temp += x - '0';
            }
            in =  to_string(temp);
            k--;
        }
        return stoi(in);
    }
};
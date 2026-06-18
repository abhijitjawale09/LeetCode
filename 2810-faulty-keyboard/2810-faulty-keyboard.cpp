class Solution {
public:
    string finalString(string s) {
        int n = s.size();
        string res = "";

        for(int i = 0;i < n; i++) {
            if(s[i] != 'i')  {
                res += s[i];
            }else{
                reverse(res.begin() , res.end());
            }
        }
        return res;
    }
};
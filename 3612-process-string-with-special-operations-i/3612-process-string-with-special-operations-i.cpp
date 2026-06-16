class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string res = "";

        int cntper = 0;
        for(auto ch : s) {
            if(ch == '#') {
                res += res;
            }else if(ch == '%'){
               reverse(res.begin() , res.end());
            }else if(ch == '*'){
                if(res.size()) {
                    res.pop_back();
                }
            }else{
                res += ch;
            }
        }
        return res;
    }
};
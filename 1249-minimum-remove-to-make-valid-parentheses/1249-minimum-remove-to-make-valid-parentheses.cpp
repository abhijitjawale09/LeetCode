class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();

        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(i);
            }else if(s[i] == ')') {
                if(!st.empty()) {
                    st.pop();
                }else {
                    s[i] = '*';
                }
            }
        }
        string res;
        while(!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }

        for(char c : s) {
            if(c != '*') {
                res += c;
            }
        }
        return res;
    }
};
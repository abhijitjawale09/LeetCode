class Solution {
public:
    int n  , len = 1;
    int solve(unordered_map<int , vector<int>>& adj, int node , string& s){

        int logest = 0 , secondlogest = 0;
        for(auto &child : adj[node]) {
            int childlen = solve(adj, child, s);

            if(s[child] == s[node]) {
                continue;
            }

            if(childlen > logest) {
                secondlogest = logest;
                logest = childlen;
            }
            else if(childlen > secondlogest) {
                secondlogest  = childlen;
            }
        }

        len = max(len , 1 + logest + secondlogest);
        return 1 + logest;
    }
    int longestPath(vector<int>& parent, string s) {
        n = parent.size();
        unordered_map<int , vector<int>> adj;

        for(int i = 0; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        solve(adj , 0 , s);

        return len;
    }
};
// public:
//     int n;
//     int len = 1;
//     int solve(unordered_map<int , vector<int>>& adj , int st , string& s) {        

//         int logest =  0 , secondlogest = 0;

//         for(auto &child : adj[st]) {
//             int childlen = solve(adj ,child, s);

//             if(s[child] == s[st]) {
//                 continue;
//             }

//             if(childlen > logest) {
//                 secondlogest = logest;
//                 logest = childlen;
//             }else if(childlen > secondlogest) {
//                 secondlogest = childlen;
//             }
//         }
//         len = max(len , logest + secondlogest + 1);
//         return logest + 1;
//     }
//     int longestPath(vector<int>& parent, string s) {
//         n = parent.size();
//         unordered_map<int , vector<int>> adj;

//         for(int i = 0; i < n; i++) {
//             int par = parent[i];
//             adj[par].push_back(i);
//         }

//         solve(adj , 0, s);
//         return len;
//     }
// };
class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();

        unordered_map<string , long long> mp;
        unordered_map<string , pair<long long , string>> imp;
        long long mx = -1;
        for(int i = 0; i < n; i++) {

            int v = views[i];
            if(mp.find(creators[i]) == mp.end()) {
                mp[creators[i]] = v;
            }else{
                mp[creators[i]] += v;
            }


            if(mx < mp[creators[i]]) {
                mx = mp[creators[i]];
            }

            if(imp.find(creators[i]) == imp.end()) {
                imp[creators[i]] = { v , ids[i]};
            }else{

                if(imp[creators[i]].first < v){
                    imp[creators[i]] = {v , ids[i]};
                }else if(imp[creators[i]].first == v &&  imp[creators[i]].second > ids[i]) {
                     imp[creators[i]] = {v , ids[i]};
                }
            }

        }

        vector<vector<string>> res;
        for(auto m : mp) {
            if(mx == m.second) {
                res.push_back({m.first , imp[m.first].second});
            }
        }
        return res;
    }
};




// class Solution {
// public:
//     vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
//         int n = creators.size();
//         vector<vector<string>> res;

//         unordered_map<string , long long> mp;
//         unordered_map<string , pair<int , string>> imp;
//         long long mx  = -1;
//         for(int i = 0; i < n; i++) {
//             long long v = views[i];
//             if(mp.find(creators[i]) == mp.end()) {
//                 mp[creators[i]] = v;
//             }else{
//                 mp[creators[i]] += v;
//             }

//             if(mx < mp[creators[i]]) mx = mp[creators[i]];

//             if(imp.find(creators[i]) == imp.end()) {
//                 imp[creators[i]] = {views[i] , ids[i]};
//             }else{
//                 if(imp[creators[i]].first < views[i]) {
//                     imp[creators[i]] = {views[i] , ids[i]};
//                 }
//                 else if(imp[creators[i]].first == views[i] && imp[creators[i]].second > ids[i]) {
//                     imp[creators[i]] = {views[i] , ids[i]};
//                 }
//             }
//         }

//         for(auto m : mp)  {
//             if(mx == m.second) {
//                 res.push_back({m.first , imp[m.first].second});
//             }
//         }
//         return res;
//     }
// };
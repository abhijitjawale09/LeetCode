class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes(n);
        int ans = -1;
        for(int i = 0; i < n; i++) {
            string time = timePoints[i];

            string hour = time.substr(0 , 2);
            string minu = time.substr(3);

            int hourit = stoi(hour);
            int minit = stoi(minu);

            minutes[i] = hourit*60 + minit;
         
        }
        sort(begin(minutes) , end(minutes));

        int result = INT_MAX;

        for(int i =  1; i < n; i++){
            result = min(result , minutes[i] - minutes[i -1]);
        }

        return min(result , (24*60) - minutes[n -1] + minutes[0]);
    }
};
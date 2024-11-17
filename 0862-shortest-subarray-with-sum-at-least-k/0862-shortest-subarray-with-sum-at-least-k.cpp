class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = INT_MAX, sum = 0;
        deque <pair<long long,long long>> q;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            
            if(sum>=k) ans = min(ans,(long long)i+1);
            
            while(!q.empty() and sum-q.front().first>=k){
                ans = min(ans,i-q.front().second);
                q.pop_front();
            }
            while(!q.empty() and sum<q.back().first) q.pop_back();
            q.push_back({sum,i});
        }
        return ans==INT_MAX ? -1 : ans;
    }
};
class Solution {
public:
    #define P pair<int , int>
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<P , vector<P> , greater<P>> pq;

        for(int i = 0; i < n; i++) {
            pq.push({nums[i],i});
        } 

        for(int i = 0; i < k; i++) {
            P tope = pq.top();
            pq.pop();

            int value = tope.first;
            int idx = tope.second;

            nums[idx] = multiplier*value;

            pq.push({nums[idx] , idx});
        }

        return nums;
    }
};
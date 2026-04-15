class Solution {
public:
    int t[21][21];

    int solve(vector<int>& nums , int i , int j) {
        if(i > j) {
            return 0;
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }

        if(i == j) {
            return nums[i];
        }

        int left = nums[i] + min(solve(nums , i + 2 , j) , solve(nums, i + 1 , j -1));
        int right = nums[j] + min(solve(nums , i , j -2) , solve(nums , i + 1, j -1));

        return t[i][j] = max(left , right);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1 , sizeof(t));
        int totalscore = accumulate(nums.begin() , nums.end() , 0);

        int play1 = solve(nums , 0 , n-1);
        int play2 = totalscore - play1;

        return play1 >= play2;
        
    }
};
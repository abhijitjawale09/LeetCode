class Solution {
public:
      int mergearr(vector<int>& arr , int st , int mid , int ed) {
        
        int j = mid + 1;
        
        int cnt = 0;
        
        for (int i = st; i <= mid; i++) {
            while (j <= ed && 1LL * arr[i] > 2LL * arr[j]) {
    j           ++;
            }
            cnt += (j - (mid + 1));
        }
        vector<int> temp;
        int left = st;
        int right = mid + 1;
        while(left <= mid && right <= ed) {
            if(arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left <= mid ) temp.push_back(arr[left++]);
        while(right <= ed) temp.push_back(arr[right++]);
        
        for(int i = st; i <= ed; i++) {
            arr[i] = temp[i - st];
        }
        return cnt;
        
    }
    int merge(vector<int>& arr , int st , int ed) {
        int cnt = 0;
        if(st >= ed) {
            return 0;
        }
        int mid = ( st + ed)/ 2;
            
        cnt += merge(arr , st , mid);
        cnt += merge(arr , mid + 1 , ed);
        cnt += mergearr(arr , st , mid , ed);
        
        return cnt;
    }
 
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return merge(nums , 0 , n -1);
    }

};


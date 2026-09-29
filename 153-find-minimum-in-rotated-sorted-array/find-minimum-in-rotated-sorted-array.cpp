class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n-1, ans = INT_MAX;
        while(s<=e){
            int mid = s + (e-s)/2;

            if(nums[s]<=nums[e]){
                ans = min(ans, nums[s]);
                break;
            }

            if(nums[s]<=nums[mid]){
                ans = min(ans, nums[s]);
                s = mid + 1;
            }else{
                e = mid-1;
                ans = min(ans, nums[mid]);
            }
        }
        return ans;
    }
};
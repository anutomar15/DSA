class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n-1, ans = INT_MAX;
        while(s<=e){
            int mid = s + (e-s)/2;

            if(nums[s] == nums[mid] && nums[mid] == nums[e]){  //shrink search space to avoid duplicates
                ans = min(ans, nums[s]);
                s++;
                e--;
                continue;
            }

            if(nums[s]<nums[e]){
                ans = min(ans, nums[s]);
                break;
            }

            if(nums[s]<=nums[mid]){
                ans = min(ans, nums[s]);
                s = mid + 1;
            }else{
                ans = min(ans, nums[mid]);
                e = mid-1;
            }
        }
        return ans;
    }
};
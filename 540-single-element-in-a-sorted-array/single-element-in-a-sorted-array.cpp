class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n-1;
        if(n==1){
            return nums[0];
        }
        while(s<=e){
            int mid = s+(e-s)/2;
            if(mid==0 && nums[0]!=nums[1]) return nums[mid];
            if(mid==n-1 && nums[n-1]!=nums[n-2]) return nums[mid];
            if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }else if(mid%2==0){ //even array
                if(nums[mid-1]==nums[mid]){ //left
                    e=mid-1;
                }else{
                    s=mid+1;
                }
            }else{ //odd array
                if(nums[mid-1]==nums[mid]){ //right
                    s=mid+1;
                }else{
                    e=mid-1;
                }
            }
        }
        return -1;
    }
};
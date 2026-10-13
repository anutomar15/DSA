class Solution {
public:
    int findLeft(vector<int> &nums, int target, int n){
        int s=0, e=n-1;
        int leftMost = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(target==nums[mid]){
                leftMost = mid;
                e=mid-1;
            }else if(nums[mid]<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return leftMost;
    }
    int findRight(vector<int> &nums, int target, int n){
        int s=0, e=n-1;
        int rightMost = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(target==nums[mid]){
                rightMost = mid;
                s=mid+1;
            }else if(nums[mid]>target){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return rightMost;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int leftMost = findLeft(nums, target, n);
        int rightMost = findRight(nums, target, n);
        return {leftMost, rightMost};
    }
};
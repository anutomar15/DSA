class Solution {
public:
    int findPivot(vector<int>& nums, int s, int e) {
    while (s < e) {
        int mid = s + (e - s) / 2;

        if (nums[mid] > nums[e]) {
            s = mid + 1;
        }
        else if (nums[mid] < nums[e]) {
            e = mid;
        }
        else {
            e--;
        }
    }

    return s;
}
    bool binarySearch(vector<int>& nums, int s, int e, int target){
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target)
                return true;
            if(nums[mid]<target)
                s = mid+1;
            else
                e = mid-1;
        }
        return false;
    }

    bool search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target)
                return true;

            // Duplicates make it impossible to identify the sorted half
            if (nums[s] == nums[mid] && nums[mid] == nums[e]) {
                s++;
                e--;
            }

            // Left half is sorted
            else if (nums[s] <= nums[mid]) {
                if (nums[s] <= target && target < nums[mid])
                    e = mid - 1;
                else
                    s = mid + 1;
            }

            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[e])
                    s = mid + 1;
                else
                    e = mid - 1;
            }
        }

        return false;
    }
};
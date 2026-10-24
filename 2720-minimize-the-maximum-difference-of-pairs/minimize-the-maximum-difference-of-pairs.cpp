class Solution {
public:
    int n;
    bool isValid(vector<int>& nums, int mid, int p){
        int count = 0;
        int i=0;
        while(i<n-1){
            if(nums[i+1]-nums[i]<=mid){
                count++;
                i+=2;
            }else{
                i++;
            }
        }
        return count>=p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        n = nums.size();
        sort(begin(nums), end(nums));
        int s = 0;
        int e = nums[n-1] - nums[0];
        int result = INT_MAX;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(isValid(nums, mid, p)){
                result =  mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return result;
    }
};
class Solution {
public:
    typedef long long ll;
    int n;
    bool isPossible(int len, const vector<int>& nums, vector<ll>& prefix, int n, const ll k){
        if(len == 0)
            return false;

        int i = 0;
        int j = len-1;
        while(j<n){
            ll target_idx = (i + j)/2;
            ll target = nums[target_idx];

            ll operations_left = 0;
            ll operations_right= 0;

            if(target_idx == 0){
                operations_left = 0;
            }else{
                operations_left = abs(((target_idx - i)*target) - (prefix[target_idx-1] - (i>0 ? prefix[i-1] : 0)));
            }

            operations_right = abs(((j - target_idx)*target) - (prefix[j]-prefix[target_idx]));

            ll totalOperations = operations_left + operations_right;

            if(totalOperations <= k){
                return true;
            }else{
                i++;
                j++;
            }
        } 
        return false;
    }

    int maxFrequencyScore(vector<int>& nums, long long k) {
        n = nums.size();
        sort(begin(nums), end(nums));

        vector<ll> prefix(n,0);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        int min_score = 1, max_score = n;
        int ans = 1;
        while(min_score<=max_score){
            int mid_score = (min_score + max_score)/2;
            if(isPossible(mid_score, nums, prefix, n, k)){
                ans = mid_score;
                min_score = mid_score + 1;
            }else{
                max_score = mid_score - 1;
            }
        }
        return ans;
    }
};
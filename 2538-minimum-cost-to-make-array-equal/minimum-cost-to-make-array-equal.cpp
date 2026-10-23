class Solution {
public:
    typedef long long ll;

    ll findCost(vector<int>& nums, vector<int>& cost, int target){
        ll result = 0;
        for(int i=0; i<nums.size(); i++){
            result += (ll)abs(nums[i]-target)*cost[i];
        }
        return result;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll ans = LLONG_MAX;
        int s = *min_element(begin(nums), end(nums));
        int e = *max_element(begin(nums), end(nums));
        
        while(s<=e){
            int mid = s + (e-s)/2;
            ll cost1 = findCost(nums, cost, mid);
            ll cost2 = findCost(nums, cost, mid+1);
            ans = min(ans,min(cost1, cost2));
            if(cost2>cost1){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans==INT_MAX ? 0:ans;
    }
};
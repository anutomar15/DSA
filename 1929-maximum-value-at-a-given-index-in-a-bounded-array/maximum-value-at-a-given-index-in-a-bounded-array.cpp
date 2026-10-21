class Solution {
public:
    typedef long long ll;
    ll getSumOfFormula(ll count, ll x){
        return (count*x)-(count * (count+1))/2;
    }

    int maxValue(int n, int index, int maxSum) {
        ll s = 1;
        ll e = maxSum;
        
        int result = 0;
        while(s<=e){
            ll mid = s + (e-s)/2;
            ll left_count = min((ll)index, mid-1);
            ll left_sum = getSumOfFormula(left_count, mid);
            left_sum += max((ll)0, index-(mid-1));

            ll right_count = min((ll)n-index-1, mid-1);
            ll right_sum = getSumOfFormula(right_count, mid);
            right_sum += max((ll)0, n-index-1-(mid-1));

            ll total_sum = left_sum + right_sum + mid;
            if(total_sum<=maxSum){
                result = max((ll)result, mid);
                s = mid + 1;
            }else{
                e = mid -1;
            }
        }
        return result;
    }
};
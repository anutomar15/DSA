class Solution {
public:
    typedef long long ll;
    bool possible(vector<int>& batteries, int mid_minutes, int n){
        ll target_minutes = (ll)n*mid_minutes;
        for(int i=0; i<batteries.size(); i++){
            target_minutes -= min((ll)batteries[i], (ll)mid_minutes);
            if(target_minutes<=0){
                return true;
            }
        }
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        ll s = *min_element(begin(batteries), end(batteries));
        ll sum_total_minutes = 0;
        for(auto& mints:batteries){
            sum_total_minutes += mints;
        }
        ll e = sum_total_minutes/n;
        ll result = 0;
        while(s<=e){
            ll mid_minutes = s + (e-s)/2;
            if(possible(batteries, mid_minutes, n)){
                result = mid_minutes;
                s = mid_minutes + 1;
            }else{
                e =  mid_minutes - 1;
            }
        }
        return result;
    }
    
};
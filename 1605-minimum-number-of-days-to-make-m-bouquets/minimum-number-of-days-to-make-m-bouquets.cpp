class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int cnt = 0;
        int noOfB = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=day){
                cnt++;
            }else{
                noOfB += (cnt/k);
                cnt = 0;
            }
        }
        noOfB += (cnt/k);
        return noOfB >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m*1LL * k*1LL;
        if(val>bloomDay.size())
            return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i=0; i<bloomDay.size(); i++){
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        }
        int s=mini, e=maxi;
        while(s<=e){
            int mid = (s+e)/2;
            if(possible(bloomDay, mid, m, k)){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
            
        }
        return s;
    }
};
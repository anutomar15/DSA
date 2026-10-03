class Solution {
public:
    int findMax(vector<int>& piles){
        int maxi = INT_MIN;
        int n = piles.size();
        for(int i=0; i<n; i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long totalHrs(vector<int>& piles, int hourly){
        long long totalHrs = 0;
        int n= piles.size();
        for(int i=0; i<n; i++){
            totalHrs += ceil((double)piles[i]/hourly);
        }
        return totalHrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1, e = findMax(piles);
        while(s<=e){
            int mid = s+(e-s)/2;
            long long hrs = totalHrs(piles, mid);
            if(hrs <= h){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return s;
    }
};
class Solution {
public:
    bool possible(vector<int>& time, long long givenTime, int totalTrips){
        long long actualTrips = 0;
        for(int &t:time){
            actualTrips += givenTime/t;
        }
        return actualTrips>=totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long s = 1;
        long long e = (long long) *min_element(begin(time),end(time))*totalTrips;
        while(s<=e){
            long long mid = s+(e-s)/2;
            if(possible(time,mid,totalTrips)){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return s;
    }
};
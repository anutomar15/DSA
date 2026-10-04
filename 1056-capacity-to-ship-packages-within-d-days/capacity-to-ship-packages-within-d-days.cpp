class Solution {
public:
    int findDays(vector<int>& weights, int cap){
        int days = 1, load = 0;
        for(int i = 0; i<weights.size(); i++){
            if(weights[i]+load>cap){
                days += 1;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s=*max_element(weights.begin(), weights.end());
        int e=accumulate(weights.begin(), weights.end(),0);
        while(s<=e){
            int mid = (s+e)/2;
            int noOfDays = findDays(weights, mid);
            if(noOfDays<=days){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return s;
    }
};
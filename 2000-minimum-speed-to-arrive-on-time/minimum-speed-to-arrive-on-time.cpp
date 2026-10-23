class Solution {
public:
    double possible(vector<int>& dist, int mid_speed){
        double time = 0.0;
        int n = dist.size();
        for(int i=0; i<n-1; i++){
            double t = (double)dist[i]/(double)mid_speed;
            time += ceil(t);
        }
        time += (double)dist[n-1]/(double)mid_speed;
        return time;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int s = 1;
        int e = 1e7;
        int minSpeed = -1;
        while(s<=e){
            int mid_speed = s + (e-s)/2;
            if(possible(dist, mid_speed)<=hour){
                minSpeed = mid_speed;
                e = mid_speed - 1;
            }else{
                s =  mid_speed + 1;
            }
        }
        return minSpeed;
    }
};
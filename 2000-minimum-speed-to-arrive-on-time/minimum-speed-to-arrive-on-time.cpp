class Solution {
    bool isPossible(vector<int>& dist, double hour, int spd){
        double time = 0;
        for(int i=0; i<dist.size(); i++){
            double trip = (double)dist[i]/spd;
            if((time+trip) > hour) return false;

            time += ceil(trip); 
        }
        return true;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1;
        int r = 10000000;
        int ans = -1;

        while(l<=r){
            int mid = l + (r-l)/2;
            if(isPossible(dist, hour, mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;   
    }
};
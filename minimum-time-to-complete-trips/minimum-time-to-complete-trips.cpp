class Solution {
    bool isPos(vector<int>& time, long long totalTrips, long long timeSpent){

        long long trips = 0;
        for(int i=0 ;i<time.size(); i++){
            trips += (timeSpent/time[i]);

            if(trips >= totalTrips) return true;
        }
        return false;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long l = 1;
        long long r = time[0];
        for(int i=1; i<time.size(); i++) r = min(r, time[i]*1ll);
        r *= totalTrips*1ll;
        
        long long ans = r;
        while(l<=r){
            long long mid = l + (r-l)/2;

            if(isPos(time, totalTrips, mid)){
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
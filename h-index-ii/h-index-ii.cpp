class Solution {
public:
    int hIndex(vector<int>& citations) {
        int hi = citations.size();   
        int lo = 0;
        // while(lo<=hi && citations[lo]==0) lo++;
        // if(lo > hi){return 0;}

        if(hi==lo){
            if(citations[lo] == 0) return 0;
            return 1;
        }

        int num = citations.size();
        int ans = 0;
        int mid = 0;
        while(lo <= hi){
            mid = lo+(hi-lo)/2;
            int cnt = lower_bound(citations.begin(),citations.end(),mid) - citations.begin();
            if((num-cnt) >= mid){
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return ans;
    }
};
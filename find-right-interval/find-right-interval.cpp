class Solution {
    int findRight(vector<vector<int>>& intervals, int idx, int n){
        int l = idx;
        int r = n-1;
        int ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(intervals[mid][0] >= intervals[idx][1]){
                ans = intervals[mid][2];
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for(int i=0; i<n; ++i){
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end());
        vector<int> ans(n,-1);
        for(int i=0; i<n; ++i){
            ans[intervals[i][2]] = findRight(intervals, i, n);
        }
        return ans;
    }
};
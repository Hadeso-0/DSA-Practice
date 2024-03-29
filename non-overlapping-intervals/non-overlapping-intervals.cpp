class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;

        sort(intervals.begin(), intervals.end()); 

        for (int i = 0; i < intervals.size()-1; ++i) {
            if (intervals[i][1] <= intervals[i+1][0]) continue;
            
            intervals[i+1][0] = intervals[i][0];
            intervals[i+1][1] = min(intervals[i][1], intervals[i+1][1]);
            ++ans;
        }

        return ans;
    }
};
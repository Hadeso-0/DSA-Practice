class Solution {
    int time_taken(vector<int>& a, vector<int>& b){
        int ans = min(abs(a[0]-b[0]), abs(a[1]-b[1]));
        ans += abs(abs(a[0]-b[0]) - abs(a[1]-b[1]));
        return ans;
    }
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i=1; i<points.size(); ++i){
            ans += time_taken(points[i], points[i-1]);
        }   
        return ans;
    }
};
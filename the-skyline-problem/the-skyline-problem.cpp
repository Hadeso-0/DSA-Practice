class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> pts;
        int n = buildings.size();
        for(int i=0;i<n; ++i){
            pts.push_back({buildings[i][0], -buildings[i][2]});
            pts.push_back({buildings[i][1],  buildings[i][2]});
        }

        sort(pts.begin(), pts.end());
        vector<vector<int>> ans;
        int curHeight = 0;
        multiset<int> prevHeights;
        prevHeights.insert(0);

        for(int i=0; i<pts.size(); ++i){
            if(pts[i][1] < 0){
                // Must be a starting point
                prevHeights.insert(-pts[i][1]);
                if(curHeight < -pts[i][1]){
                    ans.push_back({pts[i][0], -pts[i][1]});
                    curHeight = -pts[i][1];
                }
            }
            else{
                // Must be an ending point
                prevHeights.erase(prevHeights.find(pts[i][1]));
                int maxAv = (int)*prevHeights.rbegin();
                if(curHeight != maxAv){
                    curHeight = maxAv;
                    ans.push_back({pts[i][0], curHeight});
                }
            }
        }
        return ans;

    }
};
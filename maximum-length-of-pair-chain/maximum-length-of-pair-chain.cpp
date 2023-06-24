class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        
        sort(pairs.begin(), pairs.end());
        // int l = pairs[0][0];
        int r = pairs[0][1];
        int ans = 1;
        
        for(int i=1;i<pairs.size(); ++i){
            if(pairs[i][1] <= r){
                // l = pairs[i][0];
                r = pairs[i][1];
            }
            else if(pairs[i][0] > r){
                ++ans;
                // l = pairs[i][0];
                r = pairs[i][1];
            }
        }
  
        return ans;
    }
};
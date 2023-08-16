class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>> pq;
        int n = nums.size();
        
        int minV = INT_MAX; int maxV = INT_MIN;
        for(int i=0; i<n; ++i){
            pq.push({-nums[i][0], i, 0});
            minV = min(minV, nums[i][0]);
            maxV = max(maxV, nums[i][0]);
        }

        int rngS = minV; 
        int rngE = maxV; 

        while(!pq.empty()){
            minV = -pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            pq.pop();

            if((maxV - minV) < (rngE - rngS)){
                rngS = minV;
                rngE = maxV;
            }
            if(c+1 < nums[r].size()){
                pq.push({-nums[r][c+1], r, c+1});
                maxV = max(maxV, nums[r][c+1]);
            }
            else{
                break;
            }
        }
        return {rngS, rngE};
    }
};
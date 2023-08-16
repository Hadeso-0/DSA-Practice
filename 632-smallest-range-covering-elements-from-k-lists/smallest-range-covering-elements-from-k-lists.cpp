class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size(); 
        
        vector<int> ptrs(n, 0);
        int rngS = INT_MAX;
        int rngE = INT_MIN;
        int rngD = INT_MAX;
        
        while(1){
            int minV = INT_MAX;
            int maxV = INT_MIN;
            bool isOver = false;
            
            for(int i=0; i<n; ++i){
                // cout<<i<<" "<<ptrs[i]<<"  ";
                if(ptrs[i] >= nums[i].size()){
                    isOver = true;
                    break;
                } 
                minV = min(minV, nums[i][ptrs[i]]);
                maxV = max(maxV, nums[i][ptrs[i]]);
            }
            cout<<endl;
            if(isOver) break;
            
            if(rngD > (maxV-minV)){
                rngS = minV;
                rngE = maxV;
                rngD = maxV - minV;
            } 
            
            for(int i=0; i<n; ++i){
                if(nums[i][ptrs[i]] == minV){
                    ++ptrs[i];
                }
            }
        }
        return {rngS, rngE};
    }
};
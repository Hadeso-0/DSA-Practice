class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        vector<vector<int>> smt_i(n, vector<int>(n+1, 0));
        for(int i=n-2; i>=0; --i){
            smt_i[i] = smt_i[i+1];
            for(int j=0; j<nums[i+1] ; ++j){ 
                ++smt_i[i][j];
            }
        }
        vector<vector<int>> gt_i(n, vector<int>(n+1,0));
        for(int i=1; i<n;++i){
            gt_i[i] = gt_i[i-1];
            for(int j = nums[i-1]+1; j<=n; ++j){
                ++gt_i[i][j];
            }
        }

        for(int j=0; j<n; ++j){
            for(int k=j+1; k<n; ++k){
                if(nums[j] > nums[k]){
                    ans += (gt_i[j][nums[k]]*smt_i[k][nums[j]]);
                }
            }
        }
        return ans;
    }
};
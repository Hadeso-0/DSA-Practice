class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        long long ans = 1;
        int n = nums.size();
        vector<vector<int>> temp;
        for(int i=0; i<n; ++i){
            temp.push_back({nums[i], i});
        }
        sort(temp.begin(), temp.end());

        for(int i= n-2, cnt=2; i>=0; --i,++cnt){
            if(temp[i][1] > temp[i+1][1]){
                ans += cnt;
            }
            else{
                ans += 1;
            }
        }
        
        return ans;
    }
};
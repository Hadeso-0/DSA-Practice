class Solution {
    int solve(vector<int>& prefix, int i, int j){
        if(i > j) return 0;

        int tot = prefix[j] - prefix[i-1];
        int take_lft = tot - solve(prefix, i+1, j);
        int take_rgt = tot - solve(prefix, i, j-1);

        return max(take_lft, take_rgt);
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1,0);
        for(int i=0; i<n; ++i){
            prefix[i+1] = prefix[i] + nums[i];
        }
        long sum = prefix[n];
        int p1 = solve(prefix, 1, n);
        return 2*p1 >= sum;
    }
};
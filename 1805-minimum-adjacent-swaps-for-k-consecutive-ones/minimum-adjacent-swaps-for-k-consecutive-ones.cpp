class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        
        vector<long long> p;
        for (long long i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                p.push_back(i);
            }
        }

        long long n = p.size();
        vector<long long> presum(n + 1, 0);
        for (long long i = 0; i < n; ++i) {
            presum[i + 1] = presum[i] + p[i];
        }

        long long res = INT_MAX;

        if (k % 2 == 1) {
            long long radius = (k - 1) / 2;
            for (long long i = radius; i < n - radius; ++i) {
                long long right = presum[i + radius + 1] - presum[i + 1];
                long long left = presum[i] - presum[i - radius];
                res = min(res, right - left);
            }
            return res - radius * (radius + 1);
        } else {
            long long radius = (k - 2) / 2;
            for (long long i = radius; i < n - radius - 1; ++i) {
                long long right = presum[i + radius + 2] - presum[i + 1];
                long long left = presum[i] - presum[i - radius];
                res = min(res, right - left - p[i]);
            }
            return res - radius * (radius + 1) - (radius + 1);
        }
    }
};
class Solution {
public:
    double average(vector<int>& salary) {
        double ans = 0;
        int minSal = INT_MAX;
        int maxSal = INT_MIN;

        for(int i=0; i<salary.size();i++){
            ans += salary[i];
            minSal = min(minSal, salary[i]);
            maxSal = max(maxSal, salary[i]);
        }
        ans -= (minSal + maxSal);
        return ((double)ans/(double)(salary.size()-2));
    }
};
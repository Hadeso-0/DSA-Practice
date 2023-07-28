class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long extra = 0LL;
        int m = batteries.size();
        vector<int> life;
        sort(batteries.begin(), batteries.end());
        for(int i=0; i<m; ++i){
            if(i < m-n){
                extra += batteries[i];
            }
            else{
                life.push_back(batteries[i]);
            }
        }

        for(int i=0; i<n-1; ++i){
            if(extra < (long)(i+1)*(life[i+1]-life[i])){
                return life[i] + extra/(long)(i+1);
            }
            extra -= (long)(i+1)*(life[i+1]-life[i]);
        }

        return life[n-1] + extra/(long)n;
    }
};
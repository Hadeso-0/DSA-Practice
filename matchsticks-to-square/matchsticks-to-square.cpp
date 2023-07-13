class Solution {
    bool solve(int i, vector<int>& matches, int target, vector<int>& distr){
        if(i == matches.size()){
            for(int j=0; j<4; ++j) 
                if(distr[j] != target) return false;
            return true;
        }

        if(*max_element(distr.begin(), distr.end()) > target) return false;
        
        for(int j=0; j<4; ++j){
            if(distr[j]+matches[i] <= target){
                distr[j] += matches[i];
                if(solve(i+1, matches, target, distr)) return true;
                distr[j] -= matches[i];
            }
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matches) {
        int sum = 0;
        for(int i=0; i<matches.size(); ++i) sum+=matches[i];

        if((sum%4 != 0) || (sum == 0)) return false;
        int target = sum/4;

        sort(matches.begin(), matches.end(), greater<int>());
        vector<int> distr(4, 0);
        return solve(0, matches, target, distr);
    }
};
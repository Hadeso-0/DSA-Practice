class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur = 0;
        int max_alt = 0;
        for(int i=0; i<gain.size(); ++i){
            cur += gain[i];
            max_alt = max(max_alt, cur);
        }
        return max_alt;
    }
};
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevRow = 0;
        int ans = 0;
        for(int r = 0; r<bank.size(); ++r){
            int curRow = 0;
            for(int i = 0; i<bank[r].size(); ++i) curRow += (bank[r][i]-'0');

            if(curRow == 0) continue;
            else{
                ans += curRow*prevRow;
                prevRow = curRow;
            }
        }
        return ans;
    }
};
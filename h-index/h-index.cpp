class Solution {
    // bool isPos(vector<int>& cits, int x){
    //     int cnt = 0;
    //     for(auto& p : cits){
    //         if(p >= x) cnt++;
    //         if(cnt >= x) return true;
    //     }
    //     return false;
    // }
public:
    int hIndex(vector<int>& cits) {
        sort(cits.begin(), cits.end());
        int n = cits.size();
        int i;
        for(i=0; i<cits.size(); i++){
            if(cits[i] >= (n-i)){
                break;
            }
        }
        return (n-i);
    }
};
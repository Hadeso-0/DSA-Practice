class Solution {
    bool isPossible(int len, string&s , int k){
        vector<int> frq(26,0);
        for(int i=0; i<len; ++i){
            ++frq[s[i]-'A'];
        }
        int max_frq = *max_element(frq.begin(), frq.end());
        if(len - max_frq <= k) return true;
        for(int i = len; i<s.size(); ++i){
            ++frq[s[i]-'A']; --frq[s[i-len]-'A'];
           
            max_frq = *max_element(frq.begin(), frq.end());
            if(len - max_frq <= k) return true;
        }
        return false;
    }
public:
    int characterReplacement(string s, int k) {
        
        int l = 1;
        int r = s.size();
        int ans = 0;
        while(l <= r){
            int mid = l +(r-l)/2;
            if(isPossible(mid, s, k)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};
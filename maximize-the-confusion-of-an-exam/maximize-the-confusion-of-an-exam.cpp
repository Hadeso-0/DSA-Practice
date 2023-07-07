class Solution {
    int getMaxWindow(string& answerKey, char chk, int k){
        int left = 0; int right = 0;
        int cnt = 0; int ans = 0;
        while(right < answerKey.size()){
            if(answerKey[right] == chk) 
                ++cnt;

            while(cnt > k){
                if((left <= right) && (answerKey[left] == chk))
                    --cnt;
                ++left;
            }
            ans = max(ans, right-left+1);
            ++right;
        }
        return ans;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {

        // If i convert all F -> T
        int ans = getMaxWindow(answerKey, 'F', k);
        // If i convert all T -> F
        ans = max(ans, getMaxWindow(answerKey, 'T', k));

        return ans;
    }
};
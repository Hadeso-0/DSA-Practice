class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int numberOfCards = cardPoints.size();
        int start = 0; int end = numberOfCards-1;
        int leftScore = 0;
        for(start = 0; start < k; ++start) leftScore += cardPoints[start];
        --start;

        int rightScore = 0;
        int ans = leftScore + rightScore;
        
        while(start >= 0){
            // I skip the rightmost card taken cinsec form start
            leftScore -= cardPoints[start]; --start;
            rightScore += cardPoints[end]; --end;
            ans = max(ans, leftScore + rightScore);
        }
        return ans;
    }
};
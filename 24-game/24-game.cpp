class Solution {
    vector<double> allPossRes(double& a, double& b){
        vector<double> ans = {a+b, a-b, b-a, a*b};
        if(a != 0) ans.push_back(b/a);
        if(b != 0) ans.push_back(a/b);
        return ans;
    }
    bool solve(vector<double> cards){
        if(cards.size() == 1){
            return (abs(cards[0]-24) <= 0.1);
        }

        for(int i=0; i<cards.size(); ++i){
            for(int j=i+1; j<cards.size(); ++j){
                vector<double> updatedCards;
                for(int k=0; k<cards.size(); ++k){
                    if(k == i || k == j) continue;
                    updatedCards.push_back(cards[k]);
                }
                vector<double> extraTerms = allPossRes(cards[i], cards[j]);
                bool ans = false;
                for(auto& x : extraTerms){
                    updatedCards.push_back(x);
                    if(solve(updatedCards)){
                        return true;
                    }
                    updatedCards.pop_back();
                }
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> tmp(cards.begin(), cards.end());
        return solve(tmp);
    }
};
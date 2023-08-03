class Solution {
    vector<string> mapping = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solution(string num, int idx, vector<string>& ans, string temp){
        if(idx == num.size()){
            ans.push_back(temp);
            return;
        }
        if((num[idx]-'0')>=2){
            string chars = mapping[(num[idx]-'0')-2];
            for(auto c : chars){
                solution(num,idx+1,ans, temp+c);
            }
        } 
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0) return ans;
        
        solution(digits, 0, ans, "");
        return ans;
    }
};
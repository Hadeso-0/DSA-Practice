class Solution {
    static bool comparator(string& a, string& b){
        string s = a + b;
        string t = b + a;
        return s.compare(t) > 0;
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for(auto x : nums){
            temp.push_back(to_string(x));
        }
        sort(temp.begin(),temp.end(), comparator);
        
        string ans = "";
        for(auto x : temp) ans+=x;
        while(ans.size()>1 && ans[0]=='0') ans = ans.substr(1);
        return ans;
    }
};
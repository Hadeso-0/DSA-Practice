class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int idx = 0;
        int to_add = 1;
        while(idx<digits.size() && to_add != 0){
            // cout<<digits[idx]<<"->";
            digits[idx] = digits[idx] + to_add;
            to_add = digits[idx]/10;
            digits[idx] %= 10;
            // cout<<digits[idx]<<endl;
            idx++;
        }
        if(to_add != 0) digits.push_back(to_add);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
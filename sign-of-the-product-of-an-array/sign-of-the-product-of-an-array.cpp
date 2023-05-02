class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for(auto num : nums){
            if(num == 0){ans = 0; break;}
            else{
                if(num < 0){ans *= -1;}
            }
        }
        return ans;
    }
};
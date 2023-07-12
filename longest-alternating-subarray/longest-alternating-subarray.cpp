class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans = -1;
        int i = 0;
        int n = nums.size();
    
        while(i < n-1){
            int j = i+1;
            if((nums[j] - nums[i]) == 1){
                ++j;
                int len = 2;
                while(j < n){
                    if(((j-i)%2 == 0) && (nums[j] == nums[i])){
                        ++j; ++len;
                    }
                    else if(((j-i)%2 == 1) && (nums[j] == nums[i+1])){
                        ++j; ++len;
                    }
                    else{
                        break;
                    }
                }
                ans = max(ans, len);
                --j;
            }
            i = j;
        }

        return ans;
    }
};
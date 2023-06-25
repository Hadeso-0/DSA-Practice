class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                string n1 = to_string(nums[i]);
                string n2 = to_string(nums[j]); 
                if(__gcd(n1[0]-'0', n2[n2.size()-1]-'0') == 1){
                    // cout<<n1[0]<<" "<<i<<" "<<n2[n2.size()-1]<<" "<<j<<endl;
                    ++ans;
                }
            }
        }   
        return ans;
    }
};
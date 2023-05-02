class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l,r;
        l = 0;
        r = n-1;
        int l_max = 0;
        int r_max = 0;
        int ans = 0;

        while(l<r){
            if(height[l] > height[r]){
                // ans depend = right_max
                r_max = max(r_max, height[r]);
                ans += r_max - height[r];
                r--;
            }
            else{
                // ans depend on left_max
                l_max = max(l_max, height[l]);
                ans += l_max - height[l];
                l++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans = 2*z;
       
        if(x > y){
            ans += 2*(y +1 + y);
        }
        else if(x==y){
            ans += 2*(x + y);
        }
        else{
            ans += 2*(x + x + 1);
        }
       
        return ans;
    }
};
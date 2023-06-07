class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while((a>0)||(b>0)||(c>0)){
            int ba = a%2; a/=2;
            int bb = b%2; b/=2;
            int bc = c%2; c/=2;
            cout<<ba<<" "<<bb<<" "<<bc<<endl;
            if(bc == 1){
                if(ba ==1 || bb==1) continue;
                ans++;
            }
            else{
                if(ba==1 || bb==1) ans++;
                if(ba==1 && bb==1) ans++;
            }
        }
        return ans;
    }
};
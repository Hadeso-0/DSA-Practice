class Solution {
public:
    string convertToTitle(int coN) {
        string s="";
        while(coN){
            int ch = coN%26;
            if(ch==0) {
                ch=26;
                coN--;
            }
            char c = ch+'A'-1;
            s = c+s;
            // cout<<c<<" "<<coN<<endl;
            coN/=26;
        }      
        return s;
    }
};
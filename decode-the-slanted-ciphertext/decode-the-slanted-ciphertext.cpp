class Solution {
public:
    string decodeCiphertext(string encText, int rows) {
        int cols = (int)encText.size()/rows; 
        // cout<<cols;
        // for(int i=0; i<rows; ++i){
        //     cout<<"|";
        //     for(int j=0; j<cols; ++j){
        //         cout<<encText[(i*cols) + j];
        //     }
        //     cout<<"|"<<endl;
        // }
        string ans = "";
        for(int i=0; i<cols; ++i){
            int x = i;
            while(x < encText. size()){
                // cout<<x<<" ";
                ans.push_back(encText[x]);
                x =  x + cols + 1;
            }
            // cout<<endl;
        }
        while(ans.back() == ' ') ans.pop_back();
        return ans;
    }
};
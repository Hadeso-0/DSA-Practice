class Solution {
public:
    string decodeString(string s) {
        int i=0;
        string ans = "";
        for(int i=0; i<s.size(); i++){
            if(s[i]>='a' && s[i]<='z'){
                ans += s[i];
            }
            else{
                int reps = 0;
                string temp = "";
                while(s[i]>='0' && s[i]<='9'){
                    temp += s[i];
                    i++;
                }
                reps = stoi(temp);
                int brackets= 1;
                i++;
                temp = "";
                while(i<s.size() && brackets!=0){
                    if(s[i] == '[') brackets++;
                    else if(s[i] == ']') brackets--;
                    temp += s[i++];
                }
                i--;
                temp.pop_back();
                for(int k=0; k<reps; k++){
                    ans += decodeString(temp);
                }
            }
        }
        return ans;
    }
};
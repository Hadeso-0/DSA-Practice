class Solution {
    bool isVowel(char& x){
        return (x=='a' || x=='e' || x=='i' || x=='o' || x=='u');
    }
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        int n = s.size();
        for(int i=0; i<min(k,n); i++) 
            if(isVowel(s[i])) ans++;
        
        int temp = ans;
        for(int win = k; win<n; win++){
            if(isVowel(s[win])) temp++;
            if(isVowel(s[win-k])) temp--;

            ans = max(ans, temp);
        }
        return ans;
    }
};
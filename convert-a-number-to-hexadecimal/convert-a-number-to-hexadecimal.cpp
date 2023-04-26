class Solution {
public:
    string toHex(int num) {
        if(num == 0){
            return "0";
        }
        string ans = "";

        long long temp = num*1ll;
        if(temp < 0){
            temp = ((1ll<<32) + temp);
        }
        while(temp){
            long long r = temp%16;
            switch(r){
                case 0: ans += '0';
                break;
                case 1: ans += '1';
                break;
                case 2: ans += '2';
                break;
                case 3: ans += '3';
                break;
                case 4: ans += '4';
                break;
                case 5: ans += '5';
                break;
                case 6: ans += '6';
                break;
                case 7: ans += '7';
                break;
                case 8: ans += '8';
                break;
                case 9: ans += '9';
                break;
                case 10: ans += 'a';
                break;
                case 11: ans += 'b';
                break;
                case 12: ans += 'c';
                break;
                case 13: ans += 'd';
                break;
                case 14: ans += 'e';
                break;
                case 15: ans += 'f';
                break;
            }
            temp /= 16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
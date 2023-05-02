class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2 == "0"){
            return "0";
        }
        string ans = "";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int carry = 0;
        int i,j;
        for(i=0; i<num1.size(); i++){
            carry=0;
            for(j=0; j<num2.size(); j++){
                int dig = ((num1[i]-'0')*(num2[j]-'0'))+carry;
                if(i+j < ans.size()){
                    dig += (ans[i+j]-'0');
                    ans[i+j] = ((dig%10)+'0');
                    carry = dig/10;
                }
                else{
                    ans.push_back((dig%10)+'0');
                    carry = dig/10;
                }
            }
            while(carry){
                ans.push_back((carry%10)+'0');
                carry /= 10;
            }
            cout<<ans<<endl;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
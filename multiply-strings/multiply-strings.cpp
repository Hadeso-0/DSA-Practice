class Solution {
    string utilMul(string n1, char c){
        reverse(n1.begin(), n1.end());
        int x = c-'0';
        int n = n1.length();
        int carry = 0;
        for(int i=0; i<n; i++){
            int d = ((n1[i]-'0')*x)+carry;
            n1[i] = (d%10+'0');
            carry = d/10;
        }
        while(carry != 0){
            n1 += (carry%10+'0');
            carry /= 10;
        }
        reverse(n1.begin(), n1.end());
        return n1;
    }
    string utilAdd(string n1, string n2){
        reverse(n1.begin(), n1.end());
        reverse(n2.begin(), n2.end());
        int i1=0;
        int i2=0;
        int carry = 0;
        string ans = "";        
        while(i1<n1.size() && i2<n2.size()){
            int dig = (n1[i1]-'0')+(n2[i2]-'0')+carry;
            ans+=to_string(dig%10); 
            carry = dig/10;
            i1++;
            i2++;
        }
        while(i1<n1.size()){
            int dig = (n1[i1]-'0')+carry;
            ans+=to_string(dig%10); 
            carry = dig/10;
            i1++;
        }
        while(i2<n2.size()){
            int dig = (n2[i2]-'0')+carry;
            ans+=to_string(dig%10); 
            carry = dig/10;
            i2++;
        }
        while(carry){
            ans+=to_string(carry%10);
            carry/=10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2 == "0"){
            return "0";
        }
        if(num2.length() == 1){
            return utilMul(num1, num2[0]);
        }
        // cout<<utilMul("127",'2');
        int n = num2.length();
        string ans1 = utilMul(num1, num2[n-1]);
        string ans2 = multiply(num1, num2.substr(0, n-1));

        return utilAdd(ans1 , ans2+"0");
        // return " ";
    }
};
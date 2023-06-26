class Solution {
    const vector<string> ones = {"Zero","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    const vector<string> ones_line = {"Ten","Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const vector<string> tens = {"zero","one", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    const vector<string> metrics = {"", "Thousand ", "Million ", "Billion ", "Trillion "};
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        vector<string> Tempans;
        
        vector<int> tmp(3, 0);
        int metric = 0;
        while(num){
            for(int i=0; i<3; ++i){
                tmp[2-i] = num%10;
                num = num/10;
            }

            for(auto& p : tmp) cout<<p<<" ";
            cout<<" --> ";
            
            // Got my Temporary Number
            string tempStr = "";
            if(tmp[0] != 0){ // some number at Hundreds location
                tempStr += ones[tmp[0]] + " " + "Hundred ";
            }
            if(tmp[1] == 1){
                tempStr += ones_line[tmp[2]] + " ";
            }
            else{
                if(tmp[1] != 0){
                    tempStr += tens[tmp[1]] + " ";
                }
                if(tmp[2] != 0){
                    tempStr += ones[tmp[2]] + " ";
                }
            }

            Tempans.push_back(tempStr);
            cout<<tempStr;
            cout<<endl;
        }
        string ans = "";
        for(int i=0; i<Tempans.size(); ++i){
            if(Tempans[i] != "")
                ans = Tempans[i] + metrics[i] + ans;
        } 
        if(ans.size()) ans.pop_back();
        return ans;
    }
};
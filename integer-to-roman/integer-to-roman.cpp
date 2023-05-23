class Solution {
public:
    string intToRoman(int num) {
        vector<string> ones_plc  = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        vector<string> tens_plc  = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        vector<string> hnr_plc   = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        vector<string> th_plc    = {"","M","MM","MMM"};
        
        return th_plc[num/1000] + hnr_plc[(num%1000)/100] + tens_plc[(num%100)/10] + ones_plc[num%10];
    }
};
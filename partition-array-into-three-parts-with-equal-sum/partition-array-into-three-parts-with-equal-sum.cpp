class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int tot_sum = 0;
        for(int i=0; i<arr.size(); ++i){
            tot_sum += arr[i];
        }
        int part_sum = tot_sum / 3;
        if(tot_sum % 3 != 0) return false;

        int sum = 0;
        int parts = 0;
        for (int i = 0; i < arr.size()-1 && parts != 2; ++i) {
            sum += arr[i];
            if (sum == part_sum) {
                parts++;
                sum = 0;
            }
        }
        return parts == 2;
    }
};
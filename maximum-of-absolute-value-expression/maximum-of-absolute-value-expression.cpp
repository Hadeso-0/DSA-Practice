class Solution {
    int getMaxDiff(vector<int>& arr){
        int max_val = arr[0]; int min_val = arr[0];
        for(int i=1; i<arr.size(); ++i){
            max_val = max(max_val, arr[i]);
            min_val = min(min_val, arr[i]);
        }
        return (max_val - min_val);
    }
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        int max_val = INT_MIN;
        int min_val = INT_MAX;
        vector<int> v1, v2, v3, v4;
        for(int i=0; i<arr1.size(); ++i){
            v1.push_back((arr1[i] + arr2[i] + i));
            v2.push_back((arr1[i] - arr2[i] + i));
            v3.push_back((arr1[i] + arr2[i] - i));
            v4.push_back((arr1[i] - arr2[i] - i));
        }
        return max(max(getMaxDiff(v1),getMaxDiff(v2)),max(getMaxDiff(v3),getMaxDiff(v4)));
    }
};
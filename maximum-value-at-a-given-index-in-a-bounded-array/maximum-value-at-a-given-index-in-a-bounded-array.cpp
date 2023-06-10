class Solution {
    long long getSum(int s, int e, int maxVal){
        if(e < s) return 0;
        --maxVal;
        int minVal = max(0, maxVal-e+s);
        int n = maxVal-minVal+1;
        return 1LL*((n*1LL*(maxVal + minVal)/2)+(e-s+1));
    }
public:
    int maxValue(int n, int index, int maxSum) {
        int maxVal = maxSum;
        int l = 1; int r = maxSum;
        while(l<=r){
            long long mid = l + (r-l)/2;
            long long lft = getSum(0, index, mid);
            long long rgt = getSum(index+1, n-1, mid-1);
            cout<<mid<<" "<<lft<<" "<<rgt<<endl;
            if(lft + rgt <= maxSum){
                maxVal = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return maxVal;
    }
};
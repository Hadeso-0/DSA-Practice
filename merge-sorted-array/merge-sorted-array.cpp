class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int lastIdx = m+n-1;  // last index in the num1 array
        m--;  // last idx of num1
        n--;  // last idx of num2
        
        while(m>=0 && n>=0){
            if(nums1[m] > nums2[n]){
                nums1[lastIdx--] = nums1[m--];
            }
            else{
                nums1[lastIdx--] = nums2[n--];
            }
        }

        // while(m>=0) nums1[lastIdx--] = nums1[m--];
        // not needed as, nums1 mai already present hai ye elements
        
        while(n>=0) nums1[lastIdx--] = nums2[n--];
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        int j=1;
        while(i<nums.size()){
            int reps = (nums[i]==nums[i-1]);
            while(i < nums.size() && nums[i] == nums[i-1]){
                if(reps<2){
                    nums[j] = nums[i];
                    j++;
                }
                reps++;
                i++; 
            } 
            if(i==nums.size())break;
            nums[j] = nums[i];
            j++;
            i++;  
        }
        for(auto n : nums) cout<<n<<" ";
        return j;
    }
};
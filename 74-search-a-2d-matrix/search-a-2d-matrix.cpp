class Solution {
public:
    // int BSearch(vector<int>& row, int target,int s ,int e){
    //     int mid = s + (e-s)/2;
    //     if(row[mid] == target) return mid;
        
    //     if(row[mid] > target) return BSearch(row,target,s,mid-1);
    //     return BSearch(row,target,mid+1,e);
    // }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int s=0;
        int e=rows-1;
        int rowIdx = -1;

        while(s<=e){
            int mid = s+(e-s)/2;

            if(matrix[mid][cols-1] == target){
                return true;
            }
            if(target > matrix[mid][cols-1]){
                s = mid+1;
            }
            else{
                rowIdx = mid;
                e = mid-1;
            }
        }
        if(rowIdx == -1) return false;

        s=0;
        e=cols-1;
        while(s<=e){
            int mid = s+(e-s)/2;

            if(matrix[rowIdx][mid] == target){
                return true;
            }

            if(target > matrix[rowIdx][mid]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        return false;
    }
};
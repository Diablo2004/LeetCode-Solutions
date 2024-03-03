class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        
        if (matrix.empty() || matrix[0].empty())
            return false;
        if (target < matrix[0][0] || target > matrix[rows - 1][columns - 1])
            return false;
        int left=0;
        int right=matrix.size()-1;
        int column;
        while(left<=right){
            int mid= left+(right-left)/2;
            if(matrix[mid][0]<=target){
                if (mid == rows - 1 || matrix[mid + 1][0] > target) {
                    column = mid;
                    break;
                }
            }
            if(matrix[mid][0]<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        left=0;
        
        right=matrix[0].size()-1;
        while(left<=right){
            int mid= left+(right-left)/2;
            if(matrix[column][mid]==target){
                return true;
            }
            else if(matrix[column][mid]<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return false;
    }
};
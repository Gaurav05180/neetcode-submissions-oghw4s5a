class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        int low = 0, high = n-1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(matrix[mid][0] <= target && target <= matrix[mid][m-1]){
                int l=0, h=m-1;
                while(l<=h){
                    int mid2 = l + (h-l)/2;
                    if(matrix[mid][mid2]==target) return true;
                    else if(matrix[mid][mid2]<target) l = mid2+1;
                    else h = mid2-1;
                }
                return false;
            }
            else if(target > matrix[mid][m-1]) low = mid+1;
            else high = mid-1;
        }

        return false;        
    }
};

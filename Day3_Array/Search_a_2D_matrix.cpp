/*
 Search a 2D Matrix
 Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104   */

//Code:
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //so we will apply binary search
        //O(logN) N=m*n
        if(!matrix.size())return false;
        
        int n=matrix.size();//no. of rows
        int m=matrix[0].size();//no. of columns
        
        int left=0,right=m*n-1;
        int mid;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(matrix[mid/m][mid%m]==target)//row_index->[mid/m],column_index->[mid%m];
                return true;
            else if(matrix[mid/m][mid%m]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        return false;
        //element not found
    }
};

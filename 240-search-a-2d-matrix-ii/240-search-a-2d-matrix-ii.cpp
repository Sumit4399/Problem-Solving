class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
//         int r= matrix.size();
//         int c= matrix[0].size();
        
//         for(int i=0; i<r; i++)
//         {
//            for(int j=0; j<c; j++)
//            {
//                if(matrix[i][j]==target)
//                    return true;
//            }
//         }
//         return false;
        
        int r= matrix.size();
        int c= matrix[0].size();
        int i=0;
        int j= c-1;
        
        while(i<r && j>=0)
        {
            if(target>matrix[i][j])
            {
                i++;
            }
            else if(target<matrix[i][j])
            {
                j--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
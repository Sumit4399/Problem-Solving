class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        
        int n= mat.size();
        
        //first transpose matrix
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        
        //swap cols using 2-pointer approach
        for(int i=0; i<n; i++)
        {
            int left=0;
            int right= n-1;
            while(left<right)
            {
                swap(mat[i][left], mat[i][right]);
                left++;
                right--;
            }
        }
    }
};
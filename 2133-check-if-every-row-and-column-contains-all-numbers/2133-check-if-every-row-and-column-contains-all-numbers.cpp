class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        
        int n= matrix.size();
        vector<set<int>> row(n), col(n), block(n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {   
               int curr= matrix[i][j];
                if(row[i].count(curr) || col[j].count(curr))
                  // || block[(i/3)*3 + j/3].count(curr))
                {
                    return false;
                }
            
                  row[i].insert(curr);
                  col[j].insert(curr);
                  //block[(i/3)*3 + j/3].insert(curr);
            }
        }
        return true;
    }
};
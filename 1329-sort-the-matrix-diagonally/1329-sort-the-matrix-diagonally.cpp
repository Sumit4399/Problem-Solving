class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
//         int m = mat.size();
//         int n = mat[0].size();
        
//         vector<int> v;
//         for(int i=0; i<mat.size(); i++)
//         {
//             for(int j=0; j<mat[0].size(); j++)
//             {
//                 v.push_back(mat[i][j]);
//             }
//         }
        
//         sort(v.begin(), v.end());
        
//         vector<vector<int>> res;
//         for (int i = 0; i < m*n;) 
//         {
//             vector<int> tmp;
//             for (int j = 0; j < n; j++) 
//                 tmp.push_back(v[i++]);
            
//             res.push_back(tmp);
//         }
//         return res;
//     }
        
        
         for(int k = 0; k + 1 < mat.size(); k++)
             for(int i = 0; i + 1 < mat.size(); i++)
                for(int j = 0; j + 1 < mat[i].size(); j++)
                    if(mat[i][j] > mat[i + 1][j + 1])
                        swap(mat[i][j], mat[i + 1][j + 1]);   
        return mat;
    }
};
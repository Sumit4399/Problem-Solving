class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {

        //create a hash array and mark all artifacts as unvisited
        vector<vector<int>> arr(n, vector<int>(n,0));
        
        //move to all digs mark them as visited
        for(auto it : dig)
        {
            arr[it[0]][it[1]]= 1;
        }
        
        int count=0;
        for(auto it: artifacts)
        {
            int x1= it[0];
            int y1= it[1];
            int x2= it[2];
            int y2= it[3];
            bool flag= true;
            
            for(int i=x1; i<=x2; i++)
            {
                for(int j=y1; j<=y2; j++)
                {
                    if(arr[i][j]==0)
                    {
                        flag= false;
                        break;
                    }
                }
            }
            count+= flag;
        }
        
        return count;
    }
};
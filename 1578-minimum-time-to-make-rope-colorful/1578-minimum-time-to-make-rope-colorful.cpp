class Solution {
public:
    
    int minCost(string col, vector<int>& time) {
        int res= time[0], maxi= time[0];
        
        for(int i=1; i<col.size(); i++)
        {
            if(col[i] != col[i-1])
            {
                res-= maxi;
                maxi=0;
            }
            
            res+= time[i];
            maxi= max(maxi, time[i]);
        }
        return res- maxi;
    }
};
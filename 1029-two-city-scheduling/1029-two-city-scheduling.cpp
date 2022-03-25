class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int res=0;
        vector<int> b;
        //cost for sending person to city A
        for(int i=0; i<costs.size(); i++)
        {
            res+= costs[i][0];
            
            //cost if a person is send to city B
            b.push_back(costs[i][1]- costs[i][0]);
        }
        
        sort(b.begin(), b.end());
        
        for(int i=0; i<costs.size()/2; i++)
        {
           res+=b[i]; 
        }
        
        return res;
    }
};
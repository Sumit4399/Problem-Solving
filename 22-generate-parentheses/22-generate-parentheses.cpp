class Solution {
public:
    
    void find(string curr, int o, int c,vector<string> &res, int n){
        
        if(curr.size()==2*n)
        {
            res.push_back(curr);
            return;
        }
        
        if(o<n)
           find(curr+"(", o+1, c, res, n); 
        if(c<o)
           find(curr+")", o, c+1, res, n); 
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        
        find("(", 1, 0, res, n);
        return res;
    }
};
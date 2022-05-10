class Solution {
public:
    
    void solve(int start, int n, vector<int> &curr, vector<vector<int>> &res, int k){
        
        if(curr.size()==k)
        {
            res.push_back(curr);
            return;
        }
        
        for(int i=start; i<=n; i++)
        {
            curr.push_back(i);
            solve(i+1, n, curr, res, k);
            curr.pop_back(); //back_track
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        
        solve(1, n, curr, res, k);
        return res;
    }
};
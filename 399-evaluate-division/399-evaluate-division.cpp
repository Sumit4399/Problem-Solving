class Solution {
public:
    
    void dfs(string s, string d, unordered_map<string, unordered_map<string, double>> mp, 
             unordered_map<string, int> &vis, double &ans, double temp){
        
        //base cases
        if(vis.count(s))
            return;
        if(s==d)
        {
            ans=temp;
            return;
        }
        
        vis[s]=1;
        for(auto it: mp[s])
        {
            dfs(it.first, d, mp, vis, ans, temp*it.second);
        }
        return;
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& que) {
        
        //forming the graph for bi-directional given pairs
        unordered_map<string, unordered_map<string, double>> mp;
        for(int i=0; i<eq.size(); i++)
        {
            mp[eq[i][0]].insert({eq[i][1], val[i]});
            mp[eq[i][1]].insert({eq[i][0], 1.0/val[i]});
        }
        
        vector<double> res;
        //solving each query pair
        for(int i=0; i<que.size(); i++)
        {
            string source= que[i][0];
            string dest= que[i][1];
            
            unordered_map<string, int> vis;
            double ans= -1.0;
            double temp= 1;
            
            //calling dfs traversal
            if(mp.count(source))
            {
                dfs(source, dest, mp, vis, ans, temp);
            }
            res.push_back(ans);
        } 
        
        return res;
    }
};
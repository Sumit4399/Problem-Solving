class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mat) {
        
//         //creating adj list from given vector pair
//         vector<int> adj[num];
//         for(auto edge : pre)
//             adj[edge[1]].push_back(edge[0]);
        
        
        map<int,int> losers;
        set<int> winners;
        
        for(auto it : mat)
        {
            winners.insert(it[0]);        // winners
            losers[it[1]]++;              // loses
        }
        
        // counting the one loses players
        vector<int> single_lose;
        
        for(auto &[x,cnt] : losers)
        {
            if(cnt==1)
                single_lose.push_back(x);
            
            // removing the losers from the winners
            winners.erase(x);
        }
        
        return {vector<int>(winners.begin(),winners.end()),single_lose};
    }
};
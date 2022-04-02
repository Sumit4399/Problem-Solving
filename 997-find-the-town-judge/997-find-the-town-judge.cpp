class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> dis(n+1, 0);
        for(auto it : trust)
        {
            dis[it[0]]--;
            dis[it[1]]++;
        }
        
        for(int i=1; i<=n; i++)
        {
            if(dis[i]==n-1)
                return i;
        }
        
        return -1;
    }
};
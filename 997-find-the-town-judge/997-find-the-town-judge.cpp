class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
//         if(n==1)
//             return 1;
//         vector<int> dis(n+1, 0);
//         for(auto it : trust)
//         {
//             dis[it[0]]--;
//             dis[it[1]]++;
//         }
        
//         for(int i=1; i<=n; i++)
//         {
//             if(dis[i]==n-1)
//                 return i;
//         }
//         return -1;
        
        
        //using hashmap
        if(n==1)
            return 1;
        map<int, int> out;
        map<int, int> in;
        
        for(int i=0; i<trust.size(); i++)
        {
           out[trust[i][0]]++;
            in[trust[i][1]]++;
        }
        
        for(int i=1; i<=n; i++)
        {
            if(out[i]==0 && in[i]==n-1)
                return i;
        }
        
        return -1;
    }
};
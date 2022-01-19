class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        if(wordDict.size()==0) return false;
        unordered_set<string> set;
        for(int i=0; i<wordDict.size(); i++)
            set.insert(wordDict[i]);
        
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string ans = s.substr(j,i-j);
                    if(set.find(ans)!= set.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];
        
    }
};
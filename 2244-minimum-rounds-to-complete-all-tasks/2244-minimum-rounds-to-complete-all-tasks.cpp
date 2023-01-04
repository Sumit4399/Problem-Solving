class Solution {
public:
    int minimumRounds(vector<int>& t) {
        
        unordered_map<int, int> mp;
        for(int i=0; i<t.size(); i++)
        {
            mp[t[i]]++;
        }
        
        int cnt=0;
        for(auto it : mp)
        {
            if(it.second==1)
                return -1;
            
            if(it.second%3==0)
            {
                cnt+= it.second/3;
            }
            
            else
            {
                cnt+= it.second/3+1;
            }    
        }
        return cnt;
    }
};
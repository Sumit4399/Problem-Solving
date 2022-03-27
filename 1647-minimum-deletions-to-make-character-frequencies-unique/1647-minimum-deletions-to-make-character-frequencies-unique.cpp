class Solution {
public:
    int minDeletions(string s) {
        
        int ans=0;
        unordered_map<char, int> char_count;
        for(int i=0; i<size(s); i++)
        {
            char_count[s[i]]++;
        }
        
        unordered_set<int> seen;
        
        for(auto[k,v] : char_count)
        {
            while(seen.find(v) != seen.end())
            {
                v--;
                ans++;
            }
            
            if(v>0)
                seen.insert(v);
        }
        
        return ans;
    }
};
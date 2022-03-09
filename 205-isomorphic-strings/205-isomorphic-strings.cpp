class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char> mp;
        unordered_set<char> uSet;
        
        for(int i=0; i<t.length(); i++)
        {
            if(mp.find(t[i]) == mp.end())
            {
                if(uSet.find(s[i])!=uSet.end()) {
                    return false;
                }
                uSet.insert(s[i]);
                mp[t[i]]=s[i];
            }
            
            else if(mp[t[i]] != s[i])
            {
                return false;
            }
        }
        return true;
    }
};
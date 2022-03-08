class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]]++;
        }
        
        int c=0;
        for(auto it : mp)
        {
            if(it.second%2 !=0)
            {
                c++;
            }
        }
        
        if(c>1)
            return s.size()- c+1;
        
        return s.size();
    }
};
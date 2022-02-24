class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        if(ransomNote.length() > magazine.length())
            return false;
    
        int n= magazine.length();
        unordered_map<char, int> mp;
        for(int i=0; i<n; i++)
            {
               mp[magazine[i]]++; 
            }
        
            for(int i=0; i<ransomNote.length(); i++)
            {
                if(mp[ransomNote[i]] > 0)
                {
                    mp[ransomNote[i]]--;
                }
                else
                    return false;
            }
        return true;
    }
};
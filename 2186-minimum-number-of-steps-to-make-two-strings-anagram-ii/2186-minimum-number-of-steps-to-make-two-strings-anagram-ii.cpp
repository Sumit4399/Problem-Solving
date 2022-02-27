class Solution {
public:
    int minSteps(string s, string t) {
        
        int freq[26]={0};
        for(auto it : s)
            freq[it-'a']++;
        for(auto it: t)
            freq[it-'a']--;
        
        int c=0;
        for(int i=0; i<26; i++)
            c+= abs(freq[i]);
        
        return c;
    }
};
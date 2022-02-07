class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int s1= 0;
        int s2= t[s.length()];
        for(int i=0; i<s.length(); i++)
        {
            s1+= s[i];
            s2+= t[i];
        }
        
        return char(abs(s1-s2));
    }
};
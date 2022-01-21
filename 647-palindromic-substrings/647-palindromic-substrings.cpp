class Solution {
public:
    
     void palindromic(string s, int left, int right, int& c) 
     { 
        while(left >=0 && right < s.size() && s[left] == s[right]) 
        {
            c++;
            left--;
            right++;
        }
    }
    
    
    int countSubstrings(string s) {
        
        int n= s.length();
        int c=0;
        
        for(int i=0; i<n; i++)
        {
            palindromic(s,i,i,c);//for odd string length
            palindromic(s,i,i+1,c);//for odd string length
        }
        return c;
    }
};
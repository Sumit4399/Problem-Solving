class Solution {
public:
    int balancedStringSplit(string s) {
       
        int res=0;
        int c=0;
        
        for(int i=0; i<s.size(); i++)
        {
            c+= (s[i]=='L') ? 1 : -1;
            
            if(c==0)
                res++;
        }
        return res;
    }
};
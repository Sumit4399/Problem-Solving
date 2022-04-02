class Solution {
public:
    
    
    int minBitFlips(int a, int b) {
        
        vector<int>s(32,0),t(32,0);
        
        int i=0;
        while(a>0)
        {
            s[i]=(a%2);
            a/=2;
            i++;
        }
        
        i=0;
        while(b>0)
        {
            t[i]=(b%2);
            b/=2;
            i++;
        }
        
        
        int ans=0;
        for(int i=0;i<32;i++)
        {
            if(s[i]!=t[i])
                ans++;
        }
        
        return ans;
        
    }
};
class Solution {
public:
    string removeStars(string s) {
        
        string ans="";
        int c=0;
        int n= s.size();
        
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]!= '*' && c==0)
            {
                ans+= s[i];
            }
            
            else if(s[i]!= '*' && c>0)
            {
                c--;
            }
            
            else
            {
                c++;
            }
        }
        
        if(ans!= "")
            reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shift) {
        
//         vector<int> v(s.size(), 0);
//         for(auto it : shift)
//         {
//             int i= it[0];
//             int j= it[1];
//             int k= it[2];
            
//             for(; i<=j; i++)
//             {
//                 if(k==0)
//                     v[i]+= -1;
//                 else if(k==1)
//                     v[i]+= 1;
//             }
//         }
        
//         for(int i=0; i<s.size(); i++)
//         {
//             int inc_dec= (s[i] - 'a' + v[i])%26;
//             inc_dec= (inc_dec + 26)%26;
//             s[i]= 'a' + inc_dec;
//         }
//         return s;
        
        
        //line sweep method
        int n= s.size();
        vector<int> v(n+1, 0);
        for(auto it : shift)
        {
            int x= it[0];
            int y= it[1];
            
            if(it[2]==0)
            {
                v[x]--;
                v[y+1]++;
            }
            
            else
            {
                v[x]++;
                v[y+1]--;
            }
        }
        
        //prefix sum
        for(int i=1; i<=n; i++)
            v[i]= v[i]+ v[i-1];
        
        for(int i=0; i<s.size(); i++)
        {
            int inc_dec= (s[i] - 'a' + v[i])%26;
            inc_dec= (inc_dec + 26)%26;
            s[i]= 'a' + inc_dec;
        }
        return s;
    }
};
class Solution {
public:
    string greatestLetter(string s) {
        
        // int res= 0;
        // string ans;
        // unordered_set<char> set;
        // for(char c: s)
        // {
        //     if(int(c)>=97 && int(c)<=122)
        //     {
        //         int x= int(c);
        //         set.insert(x);
        //     }
        // }
        // for(int i=0; i<s.size(); i++)
        // {
        //     if((s[i]-'0')>=65 && (s[i]-'0')<=90)
        //     {
        //         int x= (s[i]-'0');
        //         if(set.find(x+32) != set.end())
        //         {
        //             if((s[i]-'0') > res)
        //             {
        //                 ans= s[i];
        //             }
        //             res= max(res, x);
        //         }
        //     }
        // }
        // if(res==0)
        //     return "";
        // return ans;
        
        
        
        vector<int> low(26), upp(26);
        string res = "";
    
        for(auto it : s) 
        {
            if(it-'A'>=0 && it-'A'<26)
                upp[it-'A']++;
            else
                low[it-'a']++;
        }
        
        for(int i=25; i>=0; i--)
        {
            if(low[i] && upp[i]) //if char found in upp and low that will be the result
            {
                res += 'A'+i; 
                break;
            }
                
        }
        return res;   
    }
};
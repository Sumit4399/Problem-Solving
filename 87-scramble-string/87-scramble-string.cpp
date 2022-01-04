class Solution {
public:
    
//     unordered_map<string,bool> mp;
    
//     bool solve(string a, string b)
//     {
//        //base cond.
//         if(a.compare(b)==0)
//            return true;
//         if(a.length()<=1)
//             return false;
        
//         string t="";
//         t= t+ a+ "" +b;
//         if(mp.find(t) != mp.end())
//             return mp[t];
        
//         int n= a.length();
//         bool flag= false;
//         for(int i=1; i<=n; i++)
//         {
//             bool c1, c2;
//             c1=c2=false;
            
//             if(solve(a.substr(0,i), b.substr(0,i)) == true && 
//                solve(a.substr(i,n-i), b.substr(i,n-i)) == true)
//                 c1=true;
            
//             if(solve(a.substr(0,i), b.substr(n-i,i)) == true && 
//                solve(a.substr(i,n-i), b.substr(0,n-i)) == true)
//                 c2=true;
            
//             if(c1 || c2)
//             {
//                 flag=true;
//                 break;
//             }
//         }
//         return mp[t]= flag;
//     }
    
    
    unordered_map<string,int>mp;
bool solve(string a,string b)
{
    if(a.compare(b)==0)
        return true;
    if(a.length()<=1)
        return false;
    string t="";
    t+=a+" "+b;
    if(mp.find(t)!=mp.end())
        return mp[t];
    int n=a.length();
    bool flag=false;
    for(int i=1;i<=n-1;i++)
    {
        bool cond1,cond2;
        cond1=cond2=false;
        if(solve(a.substr(0,i),b.substr(0,i))==true && solve(a.substr(i,n-i),b.substr(i,n-i))==true)
            cond1=true;
        if(solve(a.substr(0,i),b.substr(n-i,i))==true && solve(a.substr(i,n-i),b.substr(0,n-i))==true)
            cond2=true;
        if(cond1 || cond2)
            {
                flag=true;
                break;
            }
    }
    return mp[t]=flag;
}
    
    bool isScramble(string s1, string s2) {
        
        if(s1.length() != s2.length())
            return false;
        if(s1.length()==0 && s2.length()==0)
            return true;
        mp.clear();
        return solve(s1,s2);
    }
};
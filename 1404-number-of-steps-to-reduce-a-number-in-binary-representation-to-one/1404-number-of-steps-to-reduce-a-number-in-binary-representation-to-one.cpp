class Solution {
public:
    int numSteps(string s) {
        
//         bitset<64> b(s);
//         int dec=b.to_ulong();
//         int c=0;
        
//         while(dec>1)
//         {
//             if(dec%2==0)
//             {
//                 dec=dec/2;
//                 c++;
//             }
//             else
//             {
//                 dec=dec+1;
//                 c++;
//             }
//         }
//         return c;
        
        
        int n = s.size()-1, steps = 0 ;
        while(n>0 && s[n]=='0')
            {
                n--;
                steps++;
            }
        
        while(n)
        {            
            if(n==0) 
                break;
            
            while(n>0 && s[n]=='1')
            {
                n--; steps++;
            }
            
            if(n==0)
            {
                return steps + 2 ;
            }
            
            if(s[n]=='0')
            {
                s[n]='1' ; steps++;
            }
        }
        return steps;
    }
};
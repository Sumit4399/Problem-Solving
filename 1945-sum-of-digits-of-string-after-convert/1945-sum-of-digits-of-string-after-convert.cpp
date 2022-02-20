class Solution {
public:
    
    //storing sum of digits of a number
     int sumd(int a)
    {
        int sum=0;
        while(a)
        {
            sum+=a%10;
            a=a/10;
        }
        return sum;
    }
    
    int getLucky(string s, int k) {
        
        int sum=0;
        for(int i=0; i<s.length(); i++)
        {
            sum+= sumd(s[i]-96);
        }
        
        for(int i=1; i<k; i++)
        {
            sum= sumd(sum);
        }
        
        return sum;
    }
};
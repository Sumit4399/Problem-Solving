class Solution {
public:
    int brokenCalc(int s, int t) {
        
       int c=0;
       while(t>s)
       {
           if(t%2!=0)
           {
               t=t+1;
               c++;
           }
           else if(t%2==0)
           {
               t=t/2;
               c++;
           }
       }
        
        return c+ s-t;
    }
};
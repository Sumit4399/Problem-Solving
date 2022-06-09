class Solution {
public:
    
    //space-optimsed
    int maxProfit(vector<int>& val) {
         
         int n= val.size();
         vector<vector<int>> after(2, vector<int> (3,0));
         vector<vector<int>> curr(2, vector<int> (3,0));

         for(int i=n-1; i>=0; i--)
         {
             for(int buy=0; buy<=1; buy++)
             {
                 for(int cap=1; cap<=2; cap++)
                 {
                     int profit=0;
                     if(buy==1)
                     {
                         profit= max(-val[i] + after[0][cap], //bought
                                     0+ after[1][cap]);       //not bought
                     }
                     else
                     {
                         profit= max(val[i] + after[1][cap-1], //sold
                                     0 + after[0][cap]);    //not sold
                     }
                     curr[buy][cap]= profit;
                 }
             }
             after= curr;
         }
        return after[1][2];
    }
};
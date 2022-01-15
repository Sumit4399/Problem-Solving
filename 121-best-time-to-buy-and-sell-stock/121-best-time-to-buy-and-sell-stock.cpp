class Solution {
public:
    int maxProfit(vector<int>& prices) {
    
    int profit=0;
    int curr=prices[0];
    
    if(prices.size()<2)
        return 0;
    
    for(int i=1; i<prices.size(); i++)
    {
        if(prices[i]>prices[i-1])
            profit= max(profit, prices[i]- curr);
        
        else 
            curr= min(curr, prices[i]);
    }
   
    return profit;
    }
};
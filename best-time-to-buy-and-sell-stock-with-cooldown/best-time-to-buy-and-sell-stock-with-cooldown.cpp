class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
         int sellstate=0,cooldownstate=0,holdstate=0-prices[0],temp,temp1;
        for(int i=0;i<prices.size();i++)
        {
            temp=holdstate;
            temp1=sellstate;
            holdstate=max(holdstate,cooldownstate-prices[i]);
            sellstate=max(sellstate,temp+prices[i]);
            cooldownstate =max(cooldownstate,temp1);
        }
        return sellstate;
    }
};
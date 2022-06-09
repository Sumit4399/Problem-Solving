class Solution {
public:
    int maxProfit(vector<int>& pri) {
    
//         int profit=0;
//         int curr=prices[0];
//         if(prices.size()<2)
//             return 0;

//         for(int i=1; i<prices.size(); i++)
//         {
//             if(prices[i]>prices[i-1])
//                 profit= max(profit, prices[i]- curr);

//             else 
//                 curr= min(curr, prices[i]);
//         }
//         return profit;
//     }
        
        // int buy= INT_MAX;
        // int sell= INT_MIN;;
        // //int idx=-1;
        // for(int i=0; i<pri.size(); i++)
        // {
        //     buy= min(buy, pri[i]);
        // }
        // int idx = min_element(pri.begin(), pri.end()) - pri.begin() + 1;
        // for(int idx; idx<pri.size(); idx++)
        // {
        //     sell= max(sell, pri[idx]);
        // }
        // return sell-buy;
        
        int mini= pri[0];
        int profit= 0;

        for(int i=0; i<pri.size(); i++)
        {
            int cost= pri[i]- mini;
            profit= max(profit, cost);
            mini= min(mini, pri[i]);
        }
        return profit;
        
    }
};
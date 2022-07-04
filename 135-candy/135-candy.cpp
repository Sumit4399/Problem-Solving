class Solution {
public:
    int candy(vector<int>& rate) {
        
        int n= rate.size();
        vector<int> candy(n, 1);
        
        for(int i=1; i<n; i++)
        {
            if(rate[i] > rate[i-1])
            {
                candy[i]= candy[i-1] + 1;
            }
        }
        
        //storing the last elements's candy
        int sum= candy[n-1];
        for(int i=n-2; i>=0; i--)
        {
            if(rate[i] > rate[i+1])
            {
                candy[i]= max(candy[i], candy[i+1] + 1);
            }
            sum+= candy[i];
        }
        return sum;
    }
};
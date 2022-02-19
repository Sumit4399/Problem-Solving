class Solution {
public:
    vector<long long> maximumEvenSplit(long long s) {
        
        vector<long long> res;
        //int temp=finalSum;
        if(s%2!=0)
            return res;
        
        for (int i = 2; s - i >= i + 2; i += 2) 
        {
            res.push_back(i);
            s -= i;
        }
        res.push_back(s);
        return res;
    }
};
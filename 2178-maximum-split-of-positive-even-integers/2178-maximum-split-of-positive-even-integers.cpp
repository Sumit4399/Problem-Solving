class Solution {
public:
    vector<long long> maximumEvenSplit(long long s) {
    
        vector<long long> ans;
        if(s%2!=0)
            return ans;
   
        long long i = 2;
        long long crSum=0;
		
        while((crSum+i)<= s)
        {
            ans.push_back(i);
            crSum+=i;
            i+=2;
        }
		
		int sz = ans.size();
        ans[sz-1] += (s-crSum);
        return ans;
        
        
        //using greedy approach
//         vector<long long> res;
//         if(s%2!=0)
//             return res;
        
//         for (int i = 2; s - i >= i + 2; i += 2) 
//         {
//             res.push_back(i);
//             s -= i;
//         }
//         res.push_back(s);
//         return res;
    }
};
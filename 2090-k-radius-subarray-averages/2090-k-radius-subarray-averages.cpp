class Solution {
public:
    
//     vector<int> getAverages(vector<int>& nums, int k) {
        
//         int n= nums.size();
//         vector<int> prefix;
//         prefix.push_back(nums[0]);
//         vector<int> res;
        
//         for(int i=1; i<nums.size(); i++)
//         {
//             prefix.push_back(nums[i]+ nums[i-1]);
//         }
        
//         res.push_back(-1);
//         for(int i=0; i<n; i++)
//         {
//             int l= i-k;
//             int r= i+k;
            
//             if(l<0 || r>n-1)
//             {
//                 res.push_back(-1);
//             }
            
//             else
//             {
//                 int temp= prefix[i] - prefix[l-1] + prefix[r] - prefix[i];
//                 int ans= temp/(2*k+1);
//                 res.push_back(ans);
//             }
//         }
        
//         return res;
//     }
    
    vector<int> getAverages(vector<int>& A, int k) {
        
        int n = A.size(), len = 2 * k + 1;
        vector<int> ans(n, -1);
        
        if (n < len) 
            return ans; // If the array is too short to cover a window, return all -1s
        
        vector<long> sum(n + 1);
        for (int i = 0; i < n; ++i) 
            sum[i + 1] = sum[i] + A[i];
        for (int i = k; i + k < n; ++i) 
            ans[i] = (sum[i + k + 1] - sum[i - k]) / len;
        
        return ans;
    }
};
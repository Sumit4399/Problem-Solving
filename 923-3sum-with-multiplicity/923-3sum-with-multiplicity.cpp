class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        int mod= 1e9+7;
        int res=0;
        unordered_map<int, int> mp;
        
        for(int i=0; i<size(arr); i++)
        {
            res= (res + mp[target- arr[i]]) % mod;
               
            for(int j=0; j<i; j++)
          {
              mp[arr[i]+ arr[j]]++; 
          }
            
        }        
        return res;
            
        
//         int n = arr.size(), mod = 1e9+7, ans = 0;
//         unordered_map<int, int> m;
        
//         for(int i=0; i<n; i++) {
//             ans = (ans + m[X - arr[i]]) % mod;
            
//             for(int j=0; j<i; j++) m[arr[i] + arr[j]]++;
//         }
//         return ans;
    }
};
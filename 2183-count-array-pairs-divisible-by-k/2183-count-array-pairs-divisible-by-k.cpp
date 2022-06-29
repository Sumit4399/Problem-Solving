class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        
        // int n = nums.size();
        // long long i=0;
        // long long c=0;
        // while(i<n)
        // {
        //     for(long long j=i+1; j<n; j++)
        //     {
        //         if((nums[i]*nums[j]) % k==0)
        //         {
        //             c++;
        //         }
        //     }
        //     i++;
        // }
        // return c;
        
        
        long long ans = 0;
        unordered_map<int, int> mp;

        for (auto ele : nums) {
            // Calculate gcd of nums[i] and
            // key
            long long gcd = __gcd(k, ele);
            long long x = k / gcd;

            // Iterate over all possible gcds
            for (auto it : mp)
                if (it.first % x == 0)
                    // Add count to answer
                    ans += it.second;
            // Add gcd to map
            mp[gcd]++;
        }
        return ans;
    }
};
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
//         unordered_map<long, long>ump;
//         long long count = 0;
//         long long curr_sum = 0;
//         long long dig=0;
        
        
//         for(long long i=0;i<nums.size();i++)
//         {
//             //simple add the element into the curr_sum
//             vector<long long> temp;
//             temp.push_back(nums[i]);
//             curr_sum=curr_sum + nums[i]*temp.size();
            
//             if(curr_sum < k)
//             {
//                 count++;
//             }
            
//             if(ump.find(k- curr_sum-1)!=ump.end())
//             {
//                 count = count+ump[k- curr_sum-1];
//             }
            
//             ump[curr_sum]++;
//         }
        
//         return count;

        
        long long sum = 0, res = 0, j = 0;
        for (int i = 0; i < nums.size(); ++i) 
        {
            sum += nums[i];
            while (sum * (i - j + 1) >= k)
                sum -= nums[j++];
            res += i - j + 1;
        }
        
        return res;
    }
};
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        
//         int c=0;
//         int ind = 0;
        
//         for(int i=0; i<nums.size()-1; i++)
//         {
//             while(ind%2==0 && (i<nums.size()) && nums[i]==nums[i+1])
//             {
//                 c++;
//                 i++;
//                // ind++;
//             }
            
//             if(i<nums.size() && !(ind%2==0 && nums[i]==nums[i+1]))
//             {
//                 ind++;
//             }
//         }
        
        
//         //if array length is still odd
//         if((nums.size()-c) %2==0)
//             return c;
        
//         else
//             return c+1;
        
        
        vector<int> ans;
        int k=0;
         for(int i=0;i<nums.size();i++)
        {
            if((i-k)%2==0)
            {
                if(i<nums.size()-1 && nums[i]==nums[i+1])
                {
                    k++;
                }
                else 
                    ans.push_back(nums[i]);
            }
            else
                ans.push_back(nums[i]);
        }
       
        
        if(ans.size()%2==0)
            return nums.size() - ans.size();
        
        else
            return nums.size() - ans.size() +1;
        
    }
};
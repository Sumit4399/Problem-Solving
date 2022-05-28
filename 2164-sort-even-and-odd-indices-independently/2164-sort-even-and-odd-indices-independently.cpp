class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
       
        vector<int> res;
        priority_queue<int> odd;
        priority_queue<int, vector<int>, greater<int>> even;
        
       for(int i=0; i<nums.size(); i++)
        {
            if(i%2==0)
                even.push(nums[i]);
            else
                odd.push(nums[i]);
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            if(i%2==0)
            {
                res.push_back(even.top());
                even.pop();
            }
            else
            {
                res.push_back(odd.top());
                odd.pop();
            }
        }
        return res;
        
        
//         vector<int> odd, even;
//         for(int i = 0; i < nums.size(); i++) 
//         {
//             if(i%2==1)
//             {
//                 odd.push_back(nums[i]);
//             } 
//             else
//             {
//                 even.push_back(nums[i]);
//             }
//         }
        
//         sort(odd.begin(), odd.end(), greater<int>());
//         sort(even.begin(), even.end());
        
//         for(int i = 0; i < nums.size(); i++) 
//         {
//             if(i%2==1)
//             {
//                 nums[i] = odd[0];
//                 odd.erase(odd.begin());
//             } 
//             else 
//             {
//                 nums[i] = even[0];
//                 even.erase(even.begin());
//             }
//         }
//         return nums;
    }
};
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        vector<int> res;
        priority_queue<int> even;
        priority_queue<int> odd;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]%2==0)
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
    }
};
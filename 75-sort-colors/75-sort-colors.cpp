class Solution {
public:
    void sortColors(vector<int>& nums) {
       
//         priority_queue<int, vector<int>, greater<int>> pq;
//         for(int i=0; i<size(nums); i++)
//         {
//             pq.push(nums[i]);
//         }
        
//         int i=0;
//         while(!pq.empty())
//         {
//             int curr=pq.top();
//             pq.pop();
//             nums[i]=curr;
//             i++;
//         }
        
        
       //switch case
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        
        while(mid <= high)
        {
            switch(nums[mid])
            {
                case 0: swap(nums[low++], nums[mid++]); break;
                
                case 1: mid++; break;
                
                case 2: swap(nums[mid], nums[high--]); break;
            }
        }
        
        
    }
};
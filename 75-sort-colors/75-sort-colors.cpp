class Solution {
public:
    void sortColors(vector<int>& nums) {
       
//         priority_queue<int, vector<int>, greater<int>> pq;
   
//         for(int i; i<size(nums); i++)
//         {
//             pq.push(nums[i]);
//         }
        
        sort(nums.begin(), nums.end());
    }
};
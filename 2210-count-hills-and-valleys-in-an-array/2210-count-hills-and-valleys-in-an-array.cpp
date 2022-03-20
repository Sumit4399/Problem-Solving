class Solution {
public:
    int countHillValley(vector<int>& nums) {
        
//         int n= nums.size();
//         int hills = 0;
//         int valleys = 0;
        
//         for (int i = 1; i < n - 1; i++)
//         {
//             int j=i-1;
//             int k=i+1;
            
//             if(i>1)
//             {
//                 if(nums[i]==nums[j])
//                     j=j-1;
//                 else
//                 {
//                     if (nums[i] > nums[j] && nums[i] > nums[k]) 
//             {
//                 hills++;
//             }
            
//             if (nums[i] < nums[j] && nums[i] < nums[k]) 
//             {
//                 valleys++;
//             }
//                 }
//             }
            
//             if(i<n-2)
//             {
//                 if(nums[i]==nums[k])
//                     k=k+1;
//                 else
//                 {
//                     if (nums[i] > nums[j] && nums[i] > nums[k]) 
//             {
//                 hills++;
//             }
            
//             if (nums[i] < nums[j] && nums[i] < nums[k]) 
//             {
//                 valleys++;
//             }
//                 }
//             }

//         }
        
//         return hills + valleys;
        
        
        vector<int>v;
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                v.push_back(nums[i]);
            }
        }
        
        int c=0;
        for(int i=1;i<v.size()-1;i++){
            if(v[i]>v[i-1] and v[i]>v[i+1] or v[i]<v[i-1] and v[i]<v[i+1]){
                c++;
            }
        }
        return c;
   }
};
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
//         int peri=0;
//         int res=0;
//         int n= nums.size();
//         int i=0;
        
//         while(i<n-2)
//         {
//             vector<int> v;
//             peri=0;
//             for(int j=i; j<i+3; j++)
//             {
//                 v.push_back(nums[j]);
//                 peri+= nums[j];
//             }
//             i++;
            
//             if(v[0]==v[1] && v[1]==v[2])
//                 res= max(res, peri);
            
//             else if(v[0]!=v[1] && v[1]!=v[2] && v[0]!=v[2])
//                 res= max(res, peri);
            
//             else
//             {
//                 sort(v.begin(), v.end());
//                 if(v[0]+ v[1] == v[2])
//                     peri=0;
//                 else
//                     res= max(res, peri);
//             }
//         }
//         return res;
        
        sort(nums.begin(), nums.end());
//         int peri=0;
        
//         for(int i=1; i<nums.size(); i++)
//         {
//             if(nums[i]==nums[i-1])
//             {
//                 peri= 2*nums[i];
//             }
//         }
        
//         int maxi= *max_element (nums.begin(), nums.end());
        
//         if(maxi==peri)
//             return 0;
        
//         peri=peri+ maxi;
//         return peri;
        
        for(int i=nums.size()-1 ; i>=2; i--){
            if(nums[i]<nums[i-1]+nums[i-2])
                return nums[i]+nums[i-1]+nums[i-2];
        }
        
        return 0;
    }
};
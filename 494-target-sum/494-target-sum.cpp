class Solution {
public:
    
    int countSubset(vector<int>&arr, int sum){
        
        int n=arr.size();
        //initialise
        int t[n+1][sum+1];
        for(int i=0; i<=n; i++)
        t[i][0]= 1;
        
        for(int i=1; i<=sum; i++)
         t[0][i]= 0;
         
         //main code
         for(int i=1; i<n+1; i++)
         {
             for(int j=0; j<sum+1; j++)
             {
                 if(arr[i-1]<= j)
                 t[i][j]= t[i-1][j-arr[i-1]] + t[i-1][j];
                 
                 else
                 t[i][j]= t[i-1][j];
             }
         }
         return t[n][sum];
    }
    
    
//     int findTargetSumWays(vector<int>& nums, int target) {
        
//         int n=nums.size();
//         int sum=0;
//         for(int i=0; i<n; i++)
//         sum+= nums[i];
        
//         int res= (target + sum)/2;
//         if((target+sum)<0 || (target+sum)%2!=0)
//         {
//            return 0;
//         }
//         else
//         return countSubset(nums, res);
//     }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        
        int s2=(sum-target)/2;
        
        if((sum-target)%2==1 || target>sum)
            return 0;
        
        return countSubset(nums, s2);
    }
};
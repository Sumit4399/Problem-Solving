class Solution {
public:
    
    bool isSubsetSum(vector<int>& num, int sum){
        
        int N= num.size();
        //initialisation
        bool t[N+1][sum+1];
        for(int i=0; i<=N; i++)
        t[i][0]= true;
        
        for(int i=1; i<=sum; i++)
         t[0][i]=false;
        
        //main code
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                 
              if(num[i-1] <= j)
              t[i][j]= t[i-1][j-num[i-1]] || t[i-1][j];
        
              else 
              t[i][j]= t[i-1][j];
            }
        }
        return t[N][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        
        int n= nums.size();
        int sum=0;
        
        for(int i=0; i<n; i++)
            sum+=nums[i];
        
        if(sum%2 !=0)
            return false;
        
        else 
            return isSubsetSum(nums, sum/2);
    }
};
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> zeros(n+1,0); //for storing 0's
        vector<int> ones(n+1,0); //for storing 1's
        vector<int> total(n+1,0); //for storing sum of 0 and 1 in the partiuclar ith position
        
        for(int i=0;i<n;i++){
            if(nums[i]==0)zeros[i+1]=zeros[i]+1;
            else zeros[i+1]=zeros[i];
        }
        
        for(int i=n-1;i>=0;i--){
            if(nums[i]==1)ones[i]=ones[i+1]+1;
            else ones[i]=ones[i+1];
        }
        
        int max=0;
        for(int i=0;i<n+1;i++){
            total[i]=ones[i]+zeros[i];
            if(total[i]>max)max=total[i];
        }
        
        vector<int> ans;
        for(int i=0;i<n+1;i++){
            if(total[i]==max)ans.push_back(i);
        }
        return ans;
    }
};
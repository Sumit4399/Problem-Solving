class Solution {
public:
    
    int halveArray(vector<int>& nums) {
        
        int ans=0; 
        double sum=0;
        priority_queue<double, vector<double>> pq;
        
        for(int i=0; i<size(nums); i++)
        {
            sum+= nums[i];
            pq.push(nums[i]);
        }
       
        double req=sum/2;
        while(sum > req)
        {
            double x= pq.top();
            pq.pop();
            sum-= x/2;
            pq.push(x/2);
            ans++;
        }
        
        return ans;
    }
};
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        
        // if(total<cost1 && total<cost2)
        // return 1;

        long long n= total/cost1;
        long long ans=0;
        
        for(long long i=0; i<=n; i++)
        {
            ans+= (total- (i*cost1))/cost2 + 1;
        }
        return ans;
        
    }
};
class Solution {
public:
    int numRescueBoats(vector<int>& p, int lim) {
        
        int res=0;
        sort(p.begin(), p.end());
        int l=0;
        int r=size(p)-1;
        
        while(l<=r)
        {
            if(p[l]+p[r]> lim || p[r]==lim)
            {
                res++;
                r--;
            }
            
            else if(p[l]+p[r] <= lim)
            {
                res++;
                l++;
                r--;
            }
        }
        
        return res;
    }
};
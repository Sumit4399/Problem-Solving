class Solution {
public:
    
    bool possible(int mid, vector<int>& piles, int h){
        
        long long hours=0;
        for(int i=0; i<piles.size(); i++)
        {
            long long div= piles[i]/mid;
            hours+= div;
            if(piles[i]%mid!=0)
                hours++;
        }
        return hours<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low=1;
        int tot= *max_element(piles.begin(), piles.end());
        int high= tot;
        
        while(low<=high)
        {
            int mid= (low+high)>>1;
            if(possible(mid, piles, h))
            {
                high= mid-1;
            }
            else
            {
                low= mid+1;
            }
        }
        return low;
    }
};
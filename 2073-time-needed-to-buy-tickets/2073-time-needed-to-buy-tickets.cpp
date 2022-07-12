class Solution {
public:
    int timeRequiredToBuy(vector<int>& tic, int k) {
        
        int sec=0;
        int tar= tic[k];
        
        for(int i=0; i<tic.size(); i++)
        {
           sec+= min(tic[i], tar- (i>k));
        }
        
        return sec;
    }
};
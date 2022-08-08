class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        int cnt=0;
        vector<int> v(60, 0);
        
        for(int i=0; i<time.size(); i++)
        {
            int temp= time[i]%60;
            
            if(temp==0)
                cnt+= v[temp];
            else
                cnt+= v[60-temp];
            
            v[temp]++;
        }
        return cnt;
    }
};
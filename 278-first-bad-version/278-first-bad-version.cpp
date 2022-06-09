// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int ans= -1;
        int half= n/2;
        
        if(isBadVersion(half) == false)
        {
            for(int i= half+1; i<=n; i++)
            {
                if(isBadVersion(i) == true)
                {
                    ans=i;
                    break;
                }
            }
        }
        
        else
        {
            for(int i=half; i>0; i--)
            {
                if(isBadVersion(i) == true)
                {
                    ans=i;
                }
            }
        }
        
        return ans;
    }
};
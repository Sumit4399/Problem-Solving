class Solution {
public:
    int countCollisions(string dir) {
        
        int n= dir.size();
        if(n==1)
            return 0;
        
        int l=0;
        int r=n-1;
        
        while(l<n && dir[l]=='L')
        {
            l++;
        }
        
        while(r>0 && dir[r]=='R')
        {
            r--;
        }
        
        int c=0;
        for(int i=l; i<=r; i++)
        {
            if(dir[i] != 'S')
            {
                c++;
            }
        }
        
        return c;
    }
};
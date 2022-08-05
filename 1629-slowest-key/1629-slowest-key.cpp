class Solution {
public:
    char slowestKey(vector<int>& rel, string key) {
        
        char ans= key[0];
        int maxi= rel[0];
        
        for(int i=1; i<rel.size(); i++)
        {
            int x= rel[i]-rel[i-1];
            if(x>maxi)
            {
                maxi=x;
                ans= key[i];
            }
            
            if((x==maxi) && ans < key[i])
            {
                maxi=x;
                ans= key[i];
            }
        }
        
        return ans;
    }
};
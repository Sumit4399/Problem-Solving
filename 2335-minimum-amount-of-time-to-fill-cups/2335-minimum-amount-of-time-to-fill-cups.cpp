class Solution {
public:
    int fillCups(vector<int>& a) {
        
       int mx=0;
       int sum=0;
       for(int i=0; i<a.size(); i++)
       {
           mx= max(a[i], mx);
           sum+= a[i];
       }
        
        return max(mx, (sum+1)/2);
    }
};
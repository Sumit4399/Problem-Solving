class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        int t1=INT_MIN;
        int t2=INT_MIN;
        int n= arr.size();
        if(n<3)
            return false;
        
        for(int i=0; i<n-1; i++)
        {
            
            if(arr[i]==arr[i+1])
                return false;
            
            if(arr[i]<arr[i+1])
            {
                t1=i;
            }
        }
        
        for(int i=n-1; i>0; i--)
        {
            
             if(arr[i]==arr[i-1])
                return false;
            
            if(arr[i]<arr[i-1])
            {
                t2=i;
            }
        }
        
        if(t1+2==t2)
            return true;
        
        else 
            return false;
    }
};
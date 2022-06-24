class Solution {
public:
    bool search(vector<int>& a, int key) {
        
        int n= a.size();
        int l= 0;
        int h= n-1;
     
        while(l<=h)
        {
            int mid= (l+h)/2;
            
            if(a[mid] == key)
            return true;
            
            if((a[l] == a[mid]) && (a[h] == a[mid]))
            {
                l++;
                h--;
            }
            
            //left half is sorted
            else if(a[l]<= a[mid])
            {
                if(key>=a[l] && key<=a[mid])
                {
                    h= mid-1;
                }
                else
                {
                    l= mid+1;
                }
            }
            
            //right half is sorted
            else if(a[h]>=a[mid])
            {
                if(key>=a[mid] && key<=a[h])
                {
                    l= mid+1;
                }
                else
                {
                    h= mid-1;
                }
            }
        }
        
        return false;
    }
};
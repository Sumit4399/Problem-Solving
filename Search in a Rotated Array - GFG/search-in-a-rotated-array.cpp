// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int search(int a[], int l, int h, int key){
    
        // int n= a.size();
        // l= 0;
        // h= n-1;
      
       
        while(l<=h)
        {
            int mid= (l+h)/2;
            if(a[mid] == key)
            return mid;
            
            //left half is sorted
            if(a[l]<= a[mid])
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
            else
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
        
        return -1;
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends
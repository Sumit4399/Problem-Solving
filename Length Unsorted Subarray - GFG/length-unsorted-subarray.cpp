// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> printUnsorted(int arr[], int n) {
	    
	 int srt=-1;
	 int end=-1;
	 
	 //find the unsorted subarray
	 for(int i=0; i<n; i++)
	 {
	     if(arr[i]> arr[i+1])
	     {
	         srt=i;
	         break;
	     }
	 }
	 
	 if(srt==-1)
	 return {0,0};
	 
	 for(int i=n-1; i>0; i--)
	 {
	     if(arr[i] < arr[i-1])
	     {
	         end=i;
	         break;
	     }
	 }
	 
	 //find min and max in subarray
	 int maxi= arr[srt];
	 int mini= arr[srt];
	 
	 for(int i=srt+1; i<end+1; i++)
	 {
	     if(maxi<arr[i])
	     {
	         maxi= arr[i];
	     }
	     
	     if(mini> arr[i])
	     {
	         mini= arr[i];
	     }
	 }
	 
	 //other conditions
	 for(int i=0; i<srt; i++)
	 {
	     if(arr[i] > mini)
	     {
	         srt=i;
	         break;
	     }
	 }
	 for(int i=n-1; i>end; i--)
	 {
	     if(arr[i] < maxi)
	     {
	         end=i;
	         break;
	     }
	 }
	 
	 if(end<srt)
	 return {0,0};
	 
	 return {srt, end};
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
  // } Driver Code Ends
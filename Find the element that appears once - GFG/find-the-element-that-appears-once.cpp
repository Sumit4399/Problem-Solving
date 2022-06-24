// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int nums[], int n){
	    
        int low=0;
        int high= n-2; //because if the single element lies at last position
        
        while(high>=low)
        {
            int mid= (high + low)/2;
            if(nums[mid] == nums[mid^1])
                low= mid+1;
            else
                high= mid-1;
        }
        return nums[low];
	}
	
	//find the left-half using binary search and low will point to single element
    // right-half
    //     1st instance= odd index
    //     2nd instance= even index
    
    // left-half
    //     1st instance= even index
    //     2nd instance= odd index
    
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}
  // } Driver Code Ends
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        int maxi= arr[0];
        int curr= arr[0];
        
        for(int i=1; i<n; i++)
        {
            curr= max(arr[i], curr+arr[i]);
            maxi= max(maxi, curr);
        }
        
        return maxi;
        }
        
        
        //Kadane's Algorithm can be viewed both as a greedy and DP.
        // As we can see that we are keeping a running sum of integers 
        // and when it becomes less than 0, we reset it to 0 (Greedy Part).
        // This is because continuing with a negative sum is way more worse
        // than restarting with a new range. Now it can also be viewed as a DP, 
        // at each stage we have 2 choices: Either take the current element and
        // continue with previous sum OR restart a new range. These both choices
        // are being taken care of in the implementation. 


};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends
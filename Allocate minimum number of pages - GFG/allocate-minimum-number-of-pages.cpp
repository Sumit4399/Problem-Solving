// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isPossibleToReachHigh(int nums[], int n, int& m,int mid)
    {
        long long count=1,sum=0;
        for(int i=0;i<n;i++)
        {
            if(sum+nums[i]<=mid) sum+=nums[i];
            else
            {
                count++;
                sum=nums[i];
                if(count>m) return true; 
                //more than "m" intervals want to get separated
            }
        }
        return false; //fewer than "m" intervals want to get separated
    }
    
    
    int findPages(int nums[], int n, int m)  
    {
       // int n=nums.size();
        long long int low=INT_MIN,high=0,mid;
        for(int i=0;i<n;i++)
        {
            low=max(low,(long long int) (nums[i]));
            high+=nums[i];
        }
        while(low<high)
        {
            mid=low+(high-low)/2;
            if(isPossibleToReachHigh(nums, n, m, mid)) //increase the bar
                low=mid+1;
            else high=mid; //lower the bar
        }
        return low;
    }
    
    
    // //Function to find minimum number of pages.
    // int findPages(int A[], int N, int M) 
    // {
    //     //code here
    // }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends
// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    bool static comp(Job a, Job b)
    {
        int p1= a.profit;
        int p2= b.profit;
        
        return p1>p2;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> res;
        sort(arr, arr+n, comp);
        
        //take visited for deadline
        int m = 0;
        for(int i = 0; i < n; i++)
        {
            m = max(m, arr[i].dead);
        }
        bool slots[m];
        fill(slots, slots+m, false);
        
        int profit=0;
        int c=0;
        for(int i=0; i<n; i++)
        {
            int slot= arr[i].dead - 1;
            if(slots[slot] == false)
            {
                slots[slot] = true;
                c++;
                profit+= arr[i].profit;
            }
            else
            {
                while(slot >= 0)
                {
                    if(slots[slot] == false)
                    {
                        slots[slot]= true;
                        c++;
                        profit+= arr[i].profit;
                        break;
                    }
                    slot--;
                }
            }
        }
        res.push_back(c);
        res.push_back(profit);
        
        return res;
        
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends
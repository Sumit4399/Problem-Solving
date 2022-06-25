// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
    public:
    
    bool static comp(Item a, Item b)
    {
        double p1= (double) a.value / (double) a.weight;
        double p2= (double) b.value / (double) b.weight;
        
        return p1>p2;
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        double ans=0;
        sort(arr, arr+n, comp);
        
        for(int i=0; i<n; i++)
        {
            if(arr[i].weight <= w)
            {
                ans+= (double)arr[i].value;
                w= w- arr[i].weight;
            }
            else
            {
                ans+= (double)(w* arr[i].value)/ (double)(arr[i].weight);
                break;
            }
        }
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:

    



// 	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    //comparing first array with 2nd arr's first element and swapping
	   // for(int i=0; i<n; i++)
	   // {
	   //     if(arr1[i]> arr2[0])
	   //     {
	   //         int temp=0;
	   //         temp=arr1[i];
	   //         arr1[i]= arr2[0];
	   //         arr2[0]= temp;
	   //     }
	        
	   //     // sorting the 2nd array
	   //     int f= arr2[0];
	   //     int j;
	        
	   //     for(j=1; j<m && arr2[j]<f; j++)
	   //     {
	   //         arr2[j-1]= arr2[j];
	   //     }
	        
	   //     arr2[j-1]= f;
	   // }
	    
	   // //print the first array
	   // for(int i=0; i<n; i++)
	   // {
	   //     cout<<arr1[i]<<endl;
	   // }
	   // cout << endl;
	   // // print the 2nd array
	   //  for(int i=0; i<m; i++)
	   // {
	   //     cout<<arr2[i]<<endl;
	   // }
// 	   }
// };


// Function to find next gap.
// int nextGap(int gap)
// {
//     if (gap <= 1)
//         return 0;
//     return (gap / 2) + (gap % 2);
// }

// void merge(int* arr1, int* arr2, int n, int m)
// {
//     int i, j, gap = n + m;
//     for (gap = nextGap(gap); 
//          gap > 0; gap = nextGap(gap)) 
//     {
//         // comparing elements in the first array.
//         for (i = 0; i + gap < n; i++)
//             if (arr1[i] > arr1[i + gap])
//                 swap(arr1[i], arr1[i + gap]);

//         // comparing elements in both arrays.
//         for (j = gap > n ? gap - n : 0; 
//              i < n && j < m;
//              i++, j++)
//             if (arr1[i] > arr2[j])
//                 swap(arr1[i], arr2[j]);

//         if (j < m) {
//             // comparing elements in the second array.
//             for (j = 0; j + gap < m; j++)
//                 if (arr2[j] > arr2[j + gap])
//                     swap(arr2[j], arr2[j + gap]);
//         }
//     }
    
    void merge(int arr1[], int arr2[], int n, int m) {
	    
	    int i = n-1, j = 0;
	    
	    while(i >= 0 && j < m){
	        if(arr2[j] < arr1[i]){
	            swap(arr2[j++], arr1[i--]);
	        }else{
	            break;
	        }
	    }
	    
	    sort(arr1, arr1+n);
	    sort(arr2, arr2+m);
	
}
};

        

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
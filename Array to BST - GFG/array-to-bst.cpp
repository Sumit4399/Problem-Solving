// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    void preorder(vector<int>& nums, int i, int j,vector<int> &v){
        
        if(i<=j)
        {
            int mid= (i+j)/2;
            v.push_back(nums[mid]);
            preorder(nums, i, mid-1, v); //root->left
            preorder(nums, mid+1, j, v); //root->right
        }
    }
    
    
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        
        vector<int> v;
        int i=0, j=nums.size()-1;
        
        preorder(nums,i,j,v);
        return v;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends
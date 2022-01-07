// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:

    int solve(Node* root,int &res){
       if(!root)//base condition
           return 0;
       if(root->left==NULL && root->right==NULL){
           return root->data;
       }//base condition ends
       // hypothesis
       int l=solve(root->left,res);
       int r=solve(root->right,res);
       //induction
       //if both left andright part of tree
       //present 
       if(root->left && root->right){
           int temp=max(l,r)+root->data;
           //temp gives us the value which this node will
           //transfer to the calling node 
           int ans=(l+r+root->data);
           //ans gives us the value if the node is
           //giving the maxPath as the ultimate parent
           res=max(res,ans);
           //res is just taking the max value for 
           //output
           return temp;
       }
       if(root->left==NULL){
           int temp=r+root->data;
           //here there is no ans variable
           //as skew part cant be the maxPathSum
           return temp;
       }
       if(root->right==NULL){
           int temp=l+root->data;
           return temp;
       }
   }
   int maxPathSum(Node* root)
   {
       // code here
       int res=INT_MIN;
       int ans=solve(root,res);
       if(res!=INT_MIN){
           return res;
       }
       else{
           return ans;
       }
   }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}  // } Driver Code Ends
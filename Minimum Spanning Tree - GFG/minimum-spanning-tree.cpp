// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int N, vector<vector<int>> adj[])
    {
        // int parent[V]; //for printing the MST
        // int key[V];  //For storing the minimum dist for MST
        // bool mst[V];
        
        // for (int i = 0; i < V; i++) 
        // key[i] = INT_MAX, mst[i] = false; 
        
        // //for storing the key pair i.e index and its value
        // priority_queue<pair<int, int>, vector<int, int>>, greater<pair<int, int>> >pq;
        
        // key[0]= 0;
        // parent[0]=-1;
        // pq.push({0,0});  //pair={dis,node} 
        
        // for(int count=0; count<V-1; count++)
        // {
        //     int u= pq.top().second;
        //     pq.pop();
        //     mst[u]= true;
            
        //     for(auto it: adj[u])
        //     {
        //         int v= it[0];
        //         int weight=it[1];
                
        //         if(mst[v] == false && weight < key[v])
        //         {
        //             parent[v] =u;
        //             pq.push({key[v], v});
        //             key[v]= weight;
        //         }
        //     }
        // }
        
        // int sum=0;
        // for(int i=0; i<key.size(); i++)
        // {
        //     sum+= key[i];
        // }
        
        // return sum;
        
        
        
    int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});
    // Run the loop till all the nodes have been visited
    // because in the brute code we checked for mstSet[node] == false while computing the minimum
    // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
    // hence its better to keep running till all the nodes have been taken. 
    // try the following case: 
    // Credits: Srejan Bera
    // 6 7 
    // 0 1 5 
    // 0 2 10 
    // 0 3 100 
    // 1 3 50 
    // 1 4 200
    // 3 4 250
    // 4 5 50
    
    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u])
        {
            int v = it[0];
            int weight = it[1];
            if (mstSet[v] == false && weight < key[v])
            {
                parent[v] = u;
		        key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
    } 
    
        int sum=0;
        for(int i=0; i<N; i++)
        {
            sum+= key[i];
        }
        
        return sum;
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
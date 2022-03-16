class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        
        //creating adj list from given vector pair
        vector<int> adj[num];
        for(auto edge : pre)
            adj[edge[1]].push_back(edge[0]);
        
        queue<int> q;
 	    //find indegree of each node
 	    vector<int> indegree(num,0);
 	    for(int i=0; i<num; i++)
 	    {
 	        for(auto it : adj[i])
 	        {
 	            indegree[it]++;
 	        }
 	    }
 	    
 	    //push the node to queue if any node has 0 indegree
 	    for(int i=0; i<num; i++)
 	    {
 	        if(indegree[i]==0)
 	        {
 	            q.push(i);
 	        }
 	    }
 	    
        int ans=0;
 	    vector<int> res;
 	    while(!q.empty())
 	    {
 	        int node=q.front();
 	        q.pop();
            ans++;
 	        res.push_back(node);
 	        //find indegree of curr node pushed into the queue
 	        for(auto it : adj[node])
 	        {
 	            indegree[it]--;
 	            //if found zero push it into queue
 	            if(indegree[it]==0)
 	            {
 	                q.push(it);
 	            }
 	        }
 	    }
        
        if(ans==num)
            return res;
        else
            return {};
 	     
        
    }
};
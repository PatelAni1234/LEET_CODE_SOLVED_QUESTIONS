//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	/*oid solve(int node  ,vector<int> &vis ,vector<int> adj[] , stack<int> &s){
	     vis[node]=1;
	     
	     
	     for( auto x : adj[node]){
	         if(!vis[x]){
	             solve(x ,vis ,adj ,s);
	         }
	     }
	     s.push(node);
	}
	*/
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    /*vector<int> vis(V ,0);
	    stack<int> s;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            solve(i ,vis ,adj ,s);
	            
	        }
	    }
	    
	    vector<int> ans;
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();           ---->>using dfs
	    }
	    
	    return ans;*/
	    
	    
	    
	    queue<int> q;
	    vector<int> ans;
	    vector<int> indegree(V ,0);
	    
	    for(int i=0;i<V;i++){
	        for(auto j : adj[i]){
	            indegree[j]++ ;
	        }
	    }
	    
	    
	   
	     for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        ans.push_back(node);
	        
	        
	        for(auto i:adj[node]){
	            indegree[i]--;
	            if(indegree[i]==0){
	                q.push(i);
	            }
	        }
	       
	        
	        
	    }
	     return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
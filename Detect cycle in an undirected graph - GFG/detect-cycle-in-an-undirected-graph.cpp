//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    // Function to detect cycle in an undirected graph.
   /* bool solve(int i ,vector<int> adj[]  , vector<int> &vis){
        map<int ,int> parent;
       
        queue<int> q;    ------->>>>> //using bfs
        q.push(i);
        vis[i]=1;
        parent[i]=-1;
            
         while(!q.empty()){
            int ans = q.front();
            q.pop();
            
            
            
            
            for(auto i : adj[ans]){
                if(parent[ans]!=i && vis[i]==true){
                   return true;
               }
               else if(vis[i]==0){
                   parent[i] = ans;
                   q.push(i);
                   vis[i]=1;
               }
            }
            
        }
        return false;
    }
    */
    
      bool dfs( int node ,int parent  ,vector<int> &vis , vector<int> adj[]  ){
        
       
         
        
      
        
        vis[node] = 1;
      
      for(auto i:adj[node]){
          
          if(!vis[i]){
              
              if(dfs(i ,node   ,vis ,adj)){
                  return true;
              }
          }
          else if( parent != i ){
              return true;
          }
      }
      return false;
  }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V ,0);
        
        
      /* for(int i=0;i<V;i++){
           if(vis[i]==0){
               bool ans = solve(i ,adj  ,vis);
               
              if( ans == 1 )
                return true; 
            }
        }
        return false;
        */
        
        unordered_map<int ,int> parent;
        
       
        for(int i=0;i<V;i++){
           if(vis[i]==0){
               bool ans = dfs(i ,-1 , vis   ,adj );
               
              if( ans == 1 )
                return true; 
            }
        }
        return false;
        
       
       
       
       
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
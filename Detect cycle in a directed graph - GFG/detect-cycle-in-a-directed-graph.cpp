//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool solve(int node , vector<int> &visited ,vector<int> &dfs ,vector<int> adj[]){
        visited[node]=1;
        dfs[node]=true;
        
        
        for(auto i : adj[node]){
            if(!visited[i]){
               
                if(solve(i ,visited ,dfs ,adj)){
                   
                    return true;
                }
                
                
            }
            else if(dfs[i]==1){
                return true;
            }
            
        }
        dfs[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V ,0);
        vector<int> dfs(V ,0);
        
        for(int i=0;i<V;i++){
            
            if(!visited[i]){
                bool ans = solve(i , visited , dfs ,adj);
                if(ans==1){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
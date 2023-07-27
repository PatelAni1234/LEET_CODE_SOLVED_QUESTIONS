//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int , int> mp;
        vector<int> vis(V , 0);
        queue<int> q;
       
        
        for(int k = 0;k<V;k++){
            if(!vis[k]){
                 q.push(k);
                 vis[k] = 1;
                 mp[k] = -1;
              while(!q.empty()){
                int value = q.front();
                q.pop();
            
               for(auto i : adj[value]){
                    if(vis[i] && mp[value]!= i){
                        return true;
                    }
                    else if(!vis[i]){
                        mp[i] = value;
                        vis[i] = 1;
                        q.push(i);
                    }
                }
              }
        
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
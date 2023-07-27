//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   bool dfs(vector<int> &vis, vector<int> adj[], int node, unordered_map<int, int> &mp) {
    vis[node] = 1;

    for (auto i : adj[node]) {
        if (vis[i] && mp[node] != i) {
            return true;
        } else if (!vis[i]) {
            if (mp.find(i) == mp.end()) {
                mp[i] = node;
                if (dfs(vis, adj, i, mp)) {
                    return true;
                }
            }
        }
    }

    return false;
}

    bool isCycle(int V, vector<int> adj[]) {
       vector<int> vis(V ,0);
       unordered_map<int , int> mp;
       for(int i = 0;i<V;i++){
           if(!vis[i]){
               mp[i] = -1;
               if(dfs(vis , adj ,i , mp)){
                  return true;
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
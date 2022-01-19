#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int V, vector<int> adj[], bool vis[], int start, int parent){
        vis[start]=true;
        for(auto it: adj[start]){
            if(!vis[it]){       //if not visited already
                if(dfs(V,adj,vis,it,start)){    //check for cycle in subgraph
                    return true;
                }
            }
            else if(it != parent || it==start){         // if visited and element is not parent
                    return true;
            }
            
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool vis[V];
        memset(vis,false,V);
        for(int i=0;i<V;i++){   //to check all connected components
            if(!vis[i]){
                if(dfs(V,adj,vis,i,-1))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
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
}  // } Driver Code Ends
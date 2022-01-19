#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[], bool vis[], bool anc[], int start){
        vis[start]=true;
        anc[start]=true;
        for(auto it:adj[start]){
            if(!vis[it]){
                if(dfs(adj,vis,anc,it)){
                    return true;
                }
            }
            else if(anc[it]){
                return true;
            }
        }
        anc[start]=false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        bool vis[V],anc[V];
        memset(vis,false,V);
        memset(vis,false,V);
        for(int i=0;i<V;i++){   //to check all connected components
            if(!vis[i]){
                if(dfs(adj,vis,anc,i))
                    return true;
            }
        }
        return false;
    }
};



// { Driver Code Starts.

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
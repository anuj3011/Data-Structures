#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<int> vis(v,false);
        queue<int> q;
        vector<int> op;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int temp =q.front();
            q.pop();
            op.push_back(temp);
            for(int i=0;i<adj[temp].size();i++){
                if(!vis[adj[temp][i]]){
                    q.push(adj[temp][i]);
                    vis[adj[temp][i]]=1;
                }
            }
        }
    
        return op;
    }
    
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
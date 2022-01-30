#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//https://practice.geeksforgeeks.org/problems/mother-vertex/1

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(vector<int>adj[],int i,bool vis[]){
        vis[i]=true;
        for(auto it: adj[i]){
            if(!vis[it])
                dfs(adj,it,vis);
        }
    }
    
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    bool vis[V];
	    int lastDFSVertex=-1;
	    for(int i=0;i<V;i++)
	        vis[i]=0;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            lastDFSVertex=i;
	            dfs(adj,i,vis);
	        }
	    }
	    for(int i=0;i<V;i++)
	        vis[i]=0;
	    dfs(adj,lastDFSVertex,vis);//to verify if last dfsvertex can visit all the elements or not
	    for(int i=0;i<V;i++){
	        if(!vis[i])
	            lastDFSVertex=-1;
	    }
	    return lastDFSVertex;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
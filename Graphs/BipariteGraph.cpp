
 // } Driver Code Ends   https://practice.geeksforgeeks.org/problems/bipartite-graph/1
class Solution {
public:
    
    bool dfs(vector<int> adj[], int col[],int start, int cr){
        col[start]=cr;
        bool flag=true;
        for(auto it: adj[start]){
            if(col[it]==-1){
                flag=dfs(adj,col,it,1-cr);
                if(!flag)
                    return false;
            }else{
                if(col[it]==col[start])
                    return false;
            }
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	   // int start=0;
	    int col[V];
	    for(int i=0;i<V;i++){
	        col[i]=-1;
	    }
	    bool flag=true;
	    for(int i=0;i<V;i++){
	        if(col[i]==-1){
	            flag=dfs(adj,col,i,1);
	            if(!flag)
	                return false;
	        }
	    }
	    return true;
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
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends
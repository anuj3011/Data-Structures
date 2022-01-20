#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    int MinDist(bool proc[], vector<int> &dist,int V){
        int m=INT_MAX;
        int min_index;
        for(int i=0;i<V;i++){
            if(!proc[i] && m>dist[i]){
                m=dist[i];
                min_index=i;
            }
        }
        return min_index;
        
    }
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        // Code here
        vector<vector<int> > adj_mat(V, vector<int>(V, 0));  //converting the adj list to adj matrix
        for(int i=0; i<V; i++)
            for(int j=0; j<adj[i].size(); j++)
                adj_mat[i][adj[i][j][0]] = adj[i][j][1];
                
        
        bool proc[V]={false};
        vector<int> dist(V,INT_MAX);
        
        dist[src]=0;
        for(int i=0;i<V-1;i++){
            int u= MinDist(proc,dist,V);
            proc[u]=true;
            for(int v=0;v<V;v++){  //This works if graph is given as vector<vector<int>> adj, 
                if(adj_mat[u][v]){
                if(dist[u]+adj_mat[u][v] < dist[v])
                        dist[v]=dist[u]+adj_mat[u][v];
                    }
            }
        }
            // for(int j=0;j<V;j++){//this works for list
            //     int v=adj[u][j][0];
            //     int w=adj[u][j][1];
            //     if(dist[u]+w<dist[v]){
            //         dist[v]= dist[u]+w;
            //     }
            // }
        
        return dist;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends
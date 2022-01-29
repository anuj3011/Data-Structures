#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<vector<int> > adj_mat(V, vector<int>(V, 0));  //converting the adj list to adj matrix
        for(int i=0; i<V; i++)
            for(int j=0; j<adj[i].size(); j++)
                adj_mat[i][adj[i][j][0]] = adj[i][j][1];
                
        int dis[V];
        bool vis[V];
        int parent[V];
        for(int i=0;i<V;i++){
            dis[i]=INT_MAX;
            vis[i]=false;
            parent[i]=-1;
        }
        dis[0]=0;
        set<pair<int,int>> s;
        for(int i=0;i<V;i++){
            if(i==0)
                s.insert(make_pair(0,0));
            else
                s.insert(make_pair(INT_MAX,i));
        }
        // for(int i=0;i<V;i++){
        //     cout<<dis[i]<<" ";
            
        // }
        // cout<<endl;
        // int j=1;
        
        
        while(!s.empty()){
            auto itr= *(s.begin());
            s.erase(itr);
            int u=itr.second;
            vis[u]=true;
            for(int it=0;it<V;it++){
                if(!vis[it] && adj_mat[u][it] && dis[it]>adj_mat[u][it]){
                    s.erase(make_pair(dis[it],it));
                    dis[it]=adj_mat[u][it];
                    parent[it]=u;
                    s.insert(make_pair(dis[it],it));
                }
            }
            // cout<<j++<<" "<<endl;
            // for(auto i: s){
            //     cout<<i.first<<" "<<i.second<<endl;
            // }
            
        }
        int sum=0;
        for(int i=0;i<V;i++){
            // cout<<dis[i]<<" ";
            sum+=dis[i];
        }
        return sum;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
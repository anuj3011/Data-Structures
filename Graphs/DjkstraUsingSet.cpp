#include<bits/stdc++.h>
using namespace std;


vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        // Code here
        vector<vector<int> > adj_mat(V, vector<int>(V, 0));  //converting the adj list to adj matrix
        for(int i=0; i<V; i++)
            for(int j=0; j<adj[i].size(); j++)
                adj_mat[i][adj[i][j][0]] = adj[i][j][1];

        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        set<pair<int,int>> s;
        s.insert(make_pair(0,src));;
        while(!s.empty()){
            auto itr=*(s.begin());
            s.erase(itr);
            int u= itr.second;
            for(int v=0;v<V;v++){
                if(adj_mat[u][v]){
                    if(dist[u]+adj_mat[u][v]<dist[v]){
                        auto it= s.find(make_pair(dist[v],v));
                        if(it!=s.end()){
                            s.erase(it);
                        }
                        dist[v]=dist[u]+adj_mat[u][v];
                        s.insert(make_pair(dist[v],v));
                    }
                }
            }
        }
        return dist;
    }
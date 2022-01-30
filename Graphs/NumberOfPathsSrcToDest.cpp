//https://practice.geeksforgeeks.org/problems/count-the-paths4332/1#

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
    void dfs(vector<int>adj[], int n, int s, int d, int &count, bool vis[]){
        if(s==d){
            count++;
            return;
        }
        vis[s]=true;
        for(auto i:adj[s]){
            if(!vis[i]){
                dfs(adj,n,i,d,count,vis);
            }
        }
        vis[s]=false;
    }
    
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    bool vis[n];
	    vector<int>adj[16]; //edge list to adj list
	    for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
        }
	    int count=0;
	    for(int i=0;i<n;i++) vis[i]=false;
	    dfs(adj,n,s,d,count,vis);
	    return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
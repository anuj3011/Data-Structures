#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){ //using Bellman Ford
	    // Code here
	   //Here edges[i] is defined as (u,v,weight);
	   
	   vector<int> dis(n,INT_MAX);
	   dis[0]=0;        //taking source as 0
	   int e=edges.size();
	   for(int i=0;i<n-1;i++){
	       for(int j=0;j<e;j++){
	           int u=edges[j][0];
	           int v=edges[j][1];
	           if(dis[u]!=INT_MAX && dis[u] + edges[j][2] < dis[v]){
	               dis[v]=dis[u]+edges[j][2];
	           }
	       }
	   }



	   //for(int i=0;i<n;i++){
	   //    cout<<dis[i]<<" ";
	   //}
	   //cout<<endl;
	   for(int j=0;j<e;j++){            //this iteration is to check negative cycle
	           int u=edges[j][0];
	           int v=edges[j][1];
	           if(dis[u]!=INT_MAX && dis[u] + edges[j][2] < dis[v]){
	               return 1;
	           }
	       }
	       
	   //cout<<edges[0][0]<<" "<<edges[0][1]<<" "<<edges[0][2];
	   return 0;
	   
	    
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
//https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    bool validI(int x, int n){
        if(x<n && x>=0 )
            return true;
        // cout<<x<<" "<<y<<endl;
        return false;
    }
    bool validJ(int x, int m){
        if(x<m && x>=0 )
            return true;
        // cout<<x<<" "<<y<<endl;
        return false;
    }
    
    void checkNeighbours(pair<int,int> p, vector<vector<int>> &grid, queue<pair<int,int>> &q, int n, int m){
        int x=p.first;
        int y=p.second;
        for(int i=-1;i<2;i++){
            if(validI(x+i,n)){
                if(grid[x+i][y]==1){
                    grid[x+i][y]=2;
                    q.push({x+i,y});
                }
            }
        }
        for(int j=-1;j<2;j++){
            if(validJ(y+j,m)){
                if(grid[x][y+j]==1){
                    grid[x][y+j]=2;
                    q.push({x,y+j});
                }
            }
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int Time=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        int count=q.size();
        while(count>0){
            for(int i=0;i<count;i++){
                pair<int,int> p=q.front();
                q.pop();
                checkNeighbours(p,grid,q,n,m);
            }
            count=q.size();
            if(count>0)
                Time++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return Time;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
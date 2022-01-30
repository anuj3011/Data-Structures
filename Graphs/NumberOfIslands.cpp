// question link https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1#

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    bool vis[501][501];
    bool valid(int x, int y, int n, int m){
    if(x<n && x>=0 && y<m && y>=0)
        return true;
    // cout<<x<<" "<<y<<endl;
    return false;
    }

void dfs(vector<vector<char>>& grid, int n, int m, int i, int j){
    vis[i][j]=true;
    for(int p=-1;p<2;p++){
        for(int q=-1;q<2;q++){
            if(valid(p+i,q+j,n,m)){
                if(!vis[p+i][q+j]){
                    // cout<<p+i<<" "<<q+j<<endl;
                    dfs(grid,n,m,p+i,q+j);
                }
            }
        }
    }
}

    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='0') vis[i][j]=true;
            else vis[i][j]=false;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    count++;
                    // cout<<i<<" "<<j<<endl;
                    dfs(grid,n,m,i,j);
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends
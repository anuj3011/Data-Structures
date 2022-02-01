//https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool vis[501][501];
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
    void dfs(vector<vector<int>>& image, int n, int m, int x, int y, int newColor){
        vis[x][y]=true;
        for(int p=-1;p<2;p++){
            if(validI(p+x,n)){
                if(!vis[p+x][y]){
                    if(image[p+x][y]==image[x][y]){
                        dfs(image,n,m,p+x,y,newColor);
                        image[p+x][y]=newColor;
                    }
                }
            }
        }
        for(int q=-1;q<2;q++){
            if(validJ(q+y,m)){
                if(!vis[x][q+y] && image[x][q+y]==image[x][y]){
                    dfs(image,n,m,x,q+y,newColor);
                    image[x][q+y]=newColor;
                }
            }
        }
    }
    

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n=image.size();
        int m= image[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=false;
            }
        }
        
        dfs(image,n,m,sr,sc,newColor);
        image[sr][sc]=newColor;
        return image;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends
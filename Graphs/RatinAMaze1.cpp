// { Driver Code Starts
// Initial template for C++
//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<vector<bool>> vis;
    
    bool isPossible(int r, int c, vector<vector<int>> m, int n){
        if(r==-1 || c==-1 ||r==n || c==n || vis[r][c] || !m[r][c])
            return false;
        return true;
    }
    
    void checkPath(int r,int c, vector<vector<int>> m, int n, string &paths, vector<string> &PossiblePaths){
        if(r==n-1 && c==n-1){
            PossiblePaths.push_back(paths);
            return;
        }
        if(r==-1 || c==-1 ||r==n || c==n || vis[r][c] || !m[r][c])
            return;
            
        vis[r][c]=1;
        if(isPossible(r+1,c,m,n)){
            paths.push_back('D');
            checkPath(r+1,c,m,n,paths,PossiblePaths);
            paths.pop_back();
        }
        if(isPossible(r,c+1,m,n)){
            paths.push_back('R');
            checkPath(r,c+1,m,n,paths,PossiblePaths);
            paths.pop_back();
        }
        if(isPossible(r-1,c,m,n)){
            paths.push_back('U');
            checkPath(r-1,c,m,n,paths,PossiblePaths);
            paths.pop_back();
        }
        if(isPossible(r,c-1,m,n)){
            paths.push_back('L');
            checkPath(r,c-1,m,n,paths,PossiblePaths);
            paths.pop_back();
        }
        vis[r][c]=0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        for(int i=0;i<n;i++){
	       vis.push_back(vector<bool>(n,false));
	   }
       vector<string> PossiblePaths;
       string paths;
       checkPath(0,0,m,n,paths,PossiblePaths);
       return PossiblePaths;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
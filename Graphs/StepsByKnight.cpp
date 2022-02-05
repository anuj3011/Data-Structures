// { Driver Code Starts  https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1#
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    vector<vector<bool>> vis;
    //Function to find out minimum steps Knight needs to reach target position.
    bool isValid(int x,int y, int n){
        if(x>0 && x<=n && y>0 && y<=n){
            return true;
        }
        return false;
    }
    void addSteps(pair<int,int> p,queue<pair<int,int>> &q,int N){
        int cX[]={-1,-1,1,1,-2,2,-2,2};
        int cY[]={-2,2,-2,2,-1,-1,1,1};
        int x=p.first;
        int y=p.second;
        for(int i=0;i<8;i++){
            if(isValid(x+cX[i],y+cY[i],N)){
                if(!vis[x+cX[i]][y+cY[i]]){
                    vis[x+cX[i]][y+cY[i]]=true;
                    q.push({x+cX[i],y+cY[i]});
                }
            }
        }
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int srcX=KnightPos[0];
	    int srcY=KnightPos[1];
	    int desX=TargetPos[0];
	    int desY=TargetPos[1];
	    int steps=0;
	    queue<pair<int,int>> q;
	    if(srcX==desX && srcY==desY) 
	        return 0;
	   
	   q.push({srcX,srcY});
	   
	   for(int i=0;i<=N;i++){
	       vis.push_back(vector<bool>(N+1,false));
	   }
	   
	   vis[srcX][srcY]=true;
	   int count=q.size();
	    while(count>0){
	        for(int i=0;i<count;i++){
	            pair<int,int> p=q.front();
	            q.pop();
	            addSteps(p,q,N);
	        }
	        count=q.size();
	        
	        if(vis[desX][desY])
	            return ++steps;
	        if(count>0) steps++;
	        
	    }
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
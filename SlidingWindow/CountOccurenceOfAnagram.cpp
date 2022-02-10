// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
// int search(string pat, string txt) {   //brute
// 	    // code here
// 	    int count=0;
// 	    string str="";
// 	    int i=0,j=0;
// 	   // sort(pat.begin(),pat.end());
// 	   unordered_map<int,int> m;
// 	   for(int k=0;k<pat.length();k++)
// 	        m[s[i]]++;
// 	    while(j<txt.length()){
// 	        if(str.length()<pat.length()){
// 	            str.push_back(txt[j]);
// 	        }
// 	        if(j-i+1<pat.length()){
// 	            j++;
// 	        }else if(j-i+1==pat.length()){
// 	            string temp=str;
// 	            sort(temp.begin(),temp.end());
// 	           // cout<<str<<" "<<pat<<endl;
// 	            if(pat==temp){
// 	               // cout<<i<<" "<<j<<endl;
// 	                count++;
// 	            }
// 	            i++;
// 	            j++;
// 	            str.erase(str.begin() + 0);
// 	        }
// 	    }
// 	    return count;
// 	}
	int search(string pat, string txt) {
	    // code here
	    
	    unordered_map<char,int> m;
	    int i=0,j=0,ans=0;
	    for(int i=0;i<pat.length();i++){
	        m[pat[i]]++;
	    }
	    int count=m.size();
	    while(j<txt.length()){
	        if(m.find(txt[j])!=m.end()){
	            m[txt[j]]--;
	            if(m[txt[j]]==0)
	                count--;
	        }
	        if(j-i+1<pat.length()){
	            j++;
	        }
	        else if(j-i+1==pat.length()){
	            if(count==0){
	                ans++;
	            }
	            if(m.find(txt[i])!=m.end()){
	                m[txt[i]]++;
	                if(m[txt[i]]==1)
	                    count++;
	            }
	            i++;
	            j++;
	        }
	    }
	    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int n, int c, int pages[]){
        // code here
        map<int,int> mp;
        int cnt=0;
        for(int i=0; i<n; i++){
            if(mp.find(pages[i])==mp.end()){
                mp[pages[i]]=i;
                cnt++;
            }else{
                mp[pages[i]]=i;
            }
            int mini=INT_MAX;
            if(mp.size()>c){
                for(auto it:mp){
                    // cout<<it<<endl;
                    mini = min(it.second,mini);
                }
                mp.erase(pages[mini]);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
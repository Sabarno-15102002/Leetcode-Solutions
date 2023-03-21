//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minimumTime(int N,int cur,vector<int> &pos,vector<int> &time){
        for(int i=0;i<N;i++)
        {
            pos[i] -= cur;
            if(pos[i]<0) pos[i] *= -1;
        }
        
        int min_time = INT_MAX;
        
        for(int i=0;i<N;i++)
        {
            int t= pos[i]*time[i];
            min_time = min(min_time,t);
        }
        return min_time;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,cur;
        cin>>N>>cur;
        vector<int> pos(N),time(N);
        for(int i=0;i<N;i++){
            cin>>pos[i];
        }
        for(int i=0;i<N;i++){
            cin>>time[i];
        }
        Solution ob;
        cout<<ob.minimumTime(N,cur,pos,time)<<endl;
    }
}
// } Driver Code Ends
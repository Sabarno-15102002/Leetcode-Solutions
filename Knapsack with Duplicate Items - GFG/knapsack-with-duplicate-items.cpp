//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N+1,vector<int>(W+1,0));
        
        //base case
        
        for(int i=N-1;i>=0;i--){
            for(int w=0;w<=W;w++){
                int incl=0;
                if(w-wt[i]>=0)
                    incl=val[i]+dp[i][w-wt[i]];
                    
                int excl=0+dp[i+1][w];
                
                dp[i][w]=max(incl,excl);
            }
        }
        return dp[0][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
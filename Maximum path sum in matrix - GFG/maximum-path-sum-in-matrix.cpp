//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int dp[N][N];
        memset(dp,0,sizeof(dp));
        for(int j=0;j<N;j++) dp[0][j] = Matrix[0][j];
        for(int i=1;i<N;i++){
            for(int j=0;j<N;j++){
                int up = Matrix[i][j];
                int ld = Matrix[i][j];
                int rd = Matrix[i][j];
                up += dp[i-1][j];
                (j-1>=0) ? ld += dp[i-1][j-1] : ld += -1e8;
                (j+1<N) ? rd += dp[i-1][j+1] : rd += -1e8;
                
                dp[i][j] = max(up,max(ld,rd));
            }
        }
        int maxi = -1e8;
        for(int j=0;j<N;j++){
            maxi = max(maxi,dp[N-1][j]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
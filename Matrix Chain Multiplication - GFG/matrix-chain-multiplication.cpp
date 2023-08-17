//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[101][101];
    int matrixChainOrder(int arr[],int i,int j)
    {
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = INT_MAX;
        
        for(int k=i;k<j;k++)
        {
            dp[i][j] = min(matrixChainOrder(arr,i,k)+matrixChainOrder(arr,k+1,j)+arr[i-1]*arr[k]*arr[j],dp[i][j]);
        }
        return dp[i][j];
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int i = 1, j = N-1;
        memset(dp,-1,sizeof(dp));
        return matrixChainOrder(arr,i,j);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
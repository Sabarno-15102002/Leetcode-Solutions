//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int dp[1001][1001];
    int lps(string &A,string &B,int a,int b)
    {
        
        if(a == 0 || b == 0) return 0;
        if(dp[a][b] != -1) return dp[a][b];
        
        if(A[a-1] == B[b-1]) return dp[a][b] = 1 + lps(A,B,a-1,b-1);
        else return dp[a][b] = max(lps(A,B,a-1,b),lps(A,B,a,b-1));
    }
    int longestPalinSubseq(string A) {
        //code here
        string B = A;
        reverse(B.begin(),B.end());
        memset(dp,-1,sizeof(dp));
        int a = A.size();
        int b = B.size();
        return lps(A,B,a,b);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
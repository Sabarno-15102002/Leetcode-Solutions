//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    private:
    int M = 1e8;
    
    int fn(int n, vector<int> &dp){
        if(n == 0) return 1;
        if(n < 0) return 0;
        
        if(dp[n] != 0) return dp[n];
        
        return dp[n] = (fn(n-1, dp)%M + fn(n-2, dp)%M)%M;
    }
  public:
    int fillingBucket(int N) {
        // code here
        vector<int> dp(N+1,0);
        return fn(N,dp)%M;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
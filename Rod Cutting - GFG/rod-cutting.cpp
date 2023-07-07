//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector <int> dp(n+1);
        for(int i = 0;i < n+1;i++) dp[i] = i*price[0];
        for(int i = 1;i < n;i++){
            vector <int> t = dp;
            for(int j = 0;j < n+1;j++)
                if(i+1 <= j) t[j] = max(price[i]+t[j-i-1],dp[j]);
            dp = t;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
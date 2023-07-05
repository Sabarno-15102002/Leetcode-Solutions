//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<long long>>dp(n,vector<long long>(4,-1));
        for(int i=0;i<3;i++)dp[0][i]=points[0][i];

        for(int i=1;i<n;i++){
            for(int k=0;k<3;k++){
                
                long long ma=INT_MIN*1LL;
                for(int j=0;j<3;j++){
                    if(j!=k)
                        ma=max(ma,points[i][k]+dp[i-1][j]);
                }
            dp[i][k]=ma;
            }
        }
        long long ans=INT_MIN*1LL;
        for(int i=0;i<3;i++)ans=max(ans,dp[n-1][i]);
        return int(ans);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
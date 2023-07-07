//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int mod =(int)1e9+7;

    int findWays(vector<int> &num, int tar){
         int n = num.size();
    
        vector<vector<int>> dp(n,vector<int>(tar+1,0));
        
        if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
        else dp[0][0] = 1;  // 1 case - not pick
        
        if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick
        
        for(int ind = 1; ind<n; ind++){
            for(int target= 0; target<=tar; target++){
                
                int notTaken = dp[ind-1][target];
        
                int taken = 0;
                    if(num[ind]<=target)
                        taken = dp[ind-1][target-num[ind]];
            
                dp[ind][target]= (notTaken + taken)%mod;
            }
        }
        return dp[n-1][tar];
    }
    
    int findTargetSumWays(vector<int>&arr ,int target){
        int totSum = 0;
        int n = arr.size();
        for(int i=0; i<n;i++){
            totSum += arr[i];
        }
        
        //Checking for edge cases
        if(totSum-target <0 || (totSum-target)%2 ) return 0;
        
        return findWays(arr,(totSum-target)/2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
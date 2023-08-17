//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        // code here
        int n = str.length();
 
        int C[n][n];
        bool P[n][n];
        for (int i = 0; i < n; i++) {
            P[i][i] = true;
            C[i][i] = 0;
        }
        for (int L = 2; L <= n; L++) {
     
            for (int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1; 
                if (L == 2)
                    P[i][j] = (str[i] == str[j]);
                else
                    P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];
                if (P[i][j] == true)
                    C[i][j] = 0;
                else {
                    C[i][j] = INT_MAX;
                    for (int k = i; k <= j - 1; k++)
                        C[i][j] = min(C[i][j], C[i][k] + C[k + 1][j] + 1);
                }
            }
        }
        return C[0][n - 1];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
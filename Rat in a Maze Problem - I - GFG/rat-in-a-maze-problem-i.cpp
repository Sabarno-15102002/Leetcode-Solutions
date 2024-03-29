//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    void solve(vector<vector<int>> &m, int n,string path,int x,int y,vector<string> &ans)
    {
        if(x<0 or x>=n or y<0 or y>=n or m[x][y]==0)return;
        if(x==n-1 and y==n-1)
        {
            ans.push_back(path);
            return;
        }
        
        m[x][y]=0;
        solve(m,n,path+"D",x+1,y,ans);
        solve(m,n,path+"L",x,y-1,ans);
        solve(m,n,path+"R",x,y+1,ans);
        solve(m,n,path+"U",x-1,y,ans);
        m[x][y]=1;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string path = "";
        solve(m,n,path,0,0,ans);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
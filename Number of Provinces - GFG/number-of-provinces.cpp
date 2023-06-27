//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int index, vector<vector<int>>& adj, int V, vector<int>& vis)
    {
        vis[index]=1;
        for (int j=0; j<V; j++)
        {
            if (index != j && vis[j]==0 && adj[index][j]==1) dfs(j, adj, V, vis);
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> vis(V, 0);
        int temp = 0;
        for (int i=0; i<V; i++)
        {
            if (vis[i]==0) 
            {
                temp += 1;
                dfs(i, adj, V, vis);
            }
        }
        return temp;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    // your code here
	    for(int i = 0;i < N; i++) {
            int l = 0, r = M - 1;
            // just perform simple binary search to all row 
           // since they are sorted in increasing order
            while(l <= r) {
                int mid = l + (r - l) / 2;
                if(mat[i][mid] == X) return 1;
                else if(mat[i][mid] > X) r = mid - 1;
                else l = mid + 1;
            }
        }
        return 0;
	}
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends
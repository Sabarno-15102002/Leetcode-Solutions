//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int i=0;
	    int j=m-1;
	    int index = -1;
	    
	    while(i<n and j>=0){
	        int count = 0,max = 0;
	        if(arr[i][j] == 1){
	            count++;
	            j--;
	        }
	        else{
	            i++;
	        }
	        if(count > max){
	            max = count;
	            index = i;
	        }
	    }
	    return index;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
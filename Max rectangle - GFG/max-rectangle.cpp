//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int mah(vector<int>arr)
    {
        // Your code here
        
        // next smaller left
        int n = arr.size();
        vector<int> nsl;
        stack<pair<int,int>> s1;
        for(int i=0; i<n; i++){
            while(!s1.empty() && s1.top().first>=arr[i]){
                s1.pop();
            }
            
            if(s1.empty()){
                nsl.push_back(-1);
            }
            else{
                nsl.push_back(s1.top().second);
            }
            
            if(i<n-1 && arr[i]<arr[i+1]){
                s1.push({arr[i],i});
            }
        }
        
        
        // next smaller right
        vector<int> nsr;
        stack<pair<int,int>> s2;
        for(int i=n-1; i>=0; i--){
            while(!s2.empty() && s2.top().first>=arr[i]){
                s2.pop();
            }
            
            if(s2.empty()){
                nsr.push_back(n);
            }
            else{
                nsr.push_back(s2.top().second);
            }
            
            if(i>0 && arr[i]<arr[i-1]){
                s2.push({arr[i],i});
            }
        }
        
        reverse(nsr.begin(),nsr.end());
        
        int  maxi = 0;
        
        for(int i=0; i<n; i++){
            maxi = max(maxi,((nsr[i]-nsl[i]-1)*arr[i]));
        }
        
        return maxi;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        
        vector<vector<int>> matrix(n,vector<int>(m,0));
        
        for(int j=0; j<m; j++){
            matrix[0][j]=M[0][j];
        }
        
        
        for(int j=0; j<m; j++){
            for(int i=1; i<n; i++){
                if(M[i][j]==0){
                     matrix[i][j]=0;
                }
                else{
                    matrix[i][j]=matrix[i-1][j]+M[i][j];
                }
            }
        }
        
        
        int res = 0;
        
        for(int i=0; i<n; i++){
            res = max(res,mah(matrix[i]));
        }
        
        return res;
        
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends
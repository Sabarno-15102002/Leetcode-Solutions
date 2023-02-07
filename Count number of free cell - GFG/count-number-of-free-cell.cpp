//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int N, int K, vector<vector<int>>& arr){
      //Code Here
       vector<long long int> result(K);
      bool visitedRows[N+1];
      bool visitedColumns[N+1];
      memset(visitedRows, false, sizeof visitedRows);
      memset(visitedColumns, false, sizeof visitedColumns);
      long long numberOfNonVisitedRow = N;
      long long numberOfNonVisitedColumn = N;
    
      for (int i = 0; i < K; i++)
      {
        if (!visitedRows[arr[i][0]])
        {
            visitedRows[arr[i][0]] = true;
            numberOfNonVisitedRow--;
        }
        if (!visitedColumns[arr[i][1]])
        {
            visitedColumns[arr[i][1]] = true;
            numberOfNonVisitedColumn--;
        }
        result[i] = numberOfNonVisitedRow * numberOfNonVisitedColumn;
      }
    return result;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends
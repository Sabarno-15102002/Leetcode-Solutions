//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &mat, int n, int m, int k)
    {
        // Your code goes here
         int top=0,bottom=n-1,left=0,right=m-1,cnt=0;
         while(top<=bottom and left<=right)
         {
             for(int i=left;i<=right;i++)
             {
                 cnt++;
                 if(cnt==k) return mat[top][i];
             }
             top++;
             for(int i=top;i<=bottom;i++)
             {
                 cnt++;
                 if(cnt==k) return (mat[i][right]);
             }
             right--;
             if(top<=bottom)
             {
                 for(int i=right;i>=left;i--)
             {
                 cnt++;
                 if(cnt==k) return (mat[bottom][i]);
             }
             bottom--;
             }
             if(left<=right)
             {
                 for(int i=bottom;i>=top;i--)
                 {
                 cnt++;
                 if(cnt==k) return (mat[i][left]);
                 }
                 left++;
             }
         }
         return -1;

    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends
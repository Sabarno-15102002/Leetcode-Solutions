//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int N, int M)
{
    // write code here
    int mod =1e9+7,ans=0;
   
         int dx[]={-1,-2,-2,-1,1,2,2,1};
         int dy[]={-2,-1,1,2,2,1,-1,-2};
         
        for(long i=0;i<N;i++){
            for(long j=0;j<M;j++){
                int count=0;
                for(long k=0;k<8;k++){
                    long new_x=i+dx[k];
                    long new_y=j+dy[k];
                     if(new_x>=0 && new_x<N && new_y>=0 && new_y<M )
                    count++;
            }
             ans+=(N*M-count-1);
            ans%=mod;
       }
    }
    return ans;
}
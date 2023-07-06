//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        int i,j;
        
        for(int i=0;i<N;i++)
        {
            sum += arr[i];
        }
        
        if(sum % 2) return 0;
        
        int part[sum/2 + 1];
        
        for(int i=0;i<= sum/2;i++)
        {
            part[i] = 0;
        }
        
        for(i=0;i<N;i++)
        {
            for(j = sum/2;j >= arr[i];j--)
            {
                if (part[j - arr[i]] == 1 || j == arr[i])
                    part[j] = 1;
            }
        }
        return part[sum/2];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
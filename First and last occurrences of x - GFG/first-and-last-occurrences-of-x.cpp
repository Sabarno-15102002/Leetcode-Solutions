//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    int l = 0,h = n-1;
    vector <int> v(2,-1);
    if(!n) return v;
    while(l < h){
        int m = (l+h)/2;
        if(arr[m] < x) l = m+1;
        else h = m; 
    }
    if(arr[l] != x) return v;
    v[0] = l;
    h = n-1;
    while(l < h){
        int m = (l+h+1)/2;
        if(arr[m] > x) h = m-1;
        else l = m; 
    }
    v[1] = h;
    return v;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
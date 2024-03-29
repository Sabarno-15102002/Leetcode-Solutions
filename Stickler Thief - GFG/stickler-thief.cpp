//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int dp[10001];
    int solve(int arr[],int i)
    {
        if(i <=-1) return 0;
        if(dp[i] != -1) return dp[i];
        
        int ob1 = solve(arr,i-2) + arr[i];
        int ob2 = solve(arr,i-1);
        
        return dp[i] = max(ob1,ob2);
        
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        dp[n];
        memset(dp,-1,sizeof(dp));
        return solve(arr,n-1);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends
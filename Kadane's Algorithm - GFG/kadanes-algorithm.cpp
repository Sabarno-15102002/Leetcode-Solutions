//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long max(long long a,long long b)
    {
        return (a>b) ? a : b;
    }
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long maxSum = INT_MIN;
        long long sum = 0;
        for(int i=0;i<n;i++)
        {
            sum = max(sum+arr[i],arr[i]);
            maxSum = max(sum,maxSum);
        }
        
        return maxSum;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends
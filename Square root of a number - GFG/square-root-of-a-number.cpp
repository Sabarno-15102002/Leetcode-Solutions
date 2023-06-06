//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long int low = 0,high = x/2,mid = 0,ans = 0;
        if(x==1)
        {
            return 1;
        }
        while(low<=high)
        {
            mid =(low+high)/2;
            if(mid*mid==x)
            {
                return mid;
            }
            else if(mid*mid<x)
            {
                low = mid+1;
                ans = mid;
            }
            else
            {
                high = mid -1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends
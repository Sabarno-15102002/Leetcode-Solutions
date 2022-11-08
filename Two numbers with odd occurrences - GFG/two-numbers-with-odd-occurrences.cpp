//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
         vector<long long int>ans;

        long long int r=0,re=0,r1=0,r2=0;

        for(long long int i=0;i<N;i++)

            r^=Arr[i];

        re=r&(~(r-1));

        for(int i=0;i<N;i++)

        {

            if((Arr[i]&re)!=0)

                r1^=Arr[i];

            else

                r2^=Arr[i];

        }

        ans.emplace_back(max(r1,r2));

        ans.emplace_back(min(r1,r2));

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
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
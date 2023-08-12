//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void fun(vector<int> arr, int index, vector<int>& sums, int sum)
    {
        if(index == arr.size())
        {
            sums.push_back(sum);
            return ;
        }
        
        fun(arr, index+1, sums, sum);
        fun(arr, index+1, sums, sum+arr[index]);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> sums;
        int sum=0;
        int index=0;
        
        fun(arr, index, sums, sum);
        
        return sums;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
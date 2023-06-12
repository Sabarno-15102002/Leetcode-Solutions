// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void solve(vector<vector<int>> &ans, vector<int> arr, int s, int k, vector<int>temp, int sum)
   {
       
       for(int i=s; i<arr.size(); i++)
       {
           if(sum+arr[i]==k)
           {
               temp.push_back(arr[i]);
               ans.push_back(temp);
               return;
           }
           else if(sum+arr[i]<k)
           {
               temp.push_back(arr[i]);
               solve(ans,arr,i,k,temp,sum+arr[i]);
               temp.pop_back();
           }
           else
           {
               return;
           }
       }
   }
   vector<vector<int>> combinationSum(vector<int> A, int B) {
       // Your code here
       vector<vector<int>>ans;
       vector<int>temp;
       sort(A.begin(), A.end());
       temp.push_back(A[0]);
       for(int i=1; i<A.size(); i++)
           if(A[i]!=A[i-1])
               temp.push_back(A[i]);
       vector<int>op;        
       solve(ans,temp,0,B,op,0);
       return ans;
   }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends
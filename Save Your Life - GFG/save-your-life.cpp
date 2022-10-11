//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
        int ans = INT_MIN, curr=0;
        string res = "", s="";
        
        unordered_map<char,int> m;
        for(int i=0;i<n;i++){
            m[x[i]] = b[i];
        }
        
        for(int i=0;i<w.size();i++){
            if(m.find(w[i]) != m.end()){
                curr += m[w[i]];
            }
            else{
                if(w[i]>='a' && w[i]<='z')
                    curr += w[i];
                else{
                    curr += w[i];
                }
            }
            
            s += w[i];
            
            if(ans<curr){
                ans = curr;
                res = s;
            }
            
            if(curr<0){
                curr=0;
                s="";
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string s1, string s2){
        // code here 
        if(s1.length()==0)return 0;

        int count=0;

        int i=0,j=0;

        vector<int>r;

        while(i<s1.length()){

            if(s1[i]!=s2[j]){

                i++;

            }else{

                r.push_back(i);i++;

                if(j==s2.length()-1){

                    j=0;count++;

                    for(int k=0;k<r.size();k++)s1[r[k]]='0';

                    r.erase(r.begin(),r.end());

                     }

                else j++;

                }

        }

        if(count==0)return 0;

        int o=numberOfSubsequences(s1,s2);

        if(o==0)

        return count;

        else return count+o;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        int i=0;
        int j=0;
        int index=0;
        while(i<s1.size() && j<s2.size()){
            if(s1[i]!=s2[j]){
                i++;
            }
            else{
                if(s2[j+1]==s1[i+1] || i==s1.size()-1){
                    index=i;
                    break;
                }
                else{
                    i++;
                }
            }
            
        }
        
        string str;
        
        for(int i=0;i<s1.size();i++){
            str+=s1[(i+index)%s1.size()];
        }
        
        if(str==s2){
            return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends
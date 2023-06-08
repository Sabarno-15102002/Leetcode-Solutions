//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string final = "";
        string current = "";
        for (int i=0; i<S.length();i++){
            if (S[i] == '.'){
                final = '.' + current + final;
                current = "";
            }else{
            current+=S[i];
            }
        }
        final = current + final;
        return final;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isSubsequence(int i,int j,string str1, string str2){
        int k=0;
        while(i<=j and k<str2.length()){
            if(str1[i]==str2[k]){
                i++;
                k++;
            }
            else{
                i++;
            }
        }
        if(k==str2.length()){
            return true;
        }
        return false;
    }
    string minWindow(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        int i=0,j=0;
        int st,en,ans=INT_MAX;
        while(j<n){
            while(isSubsequence(i,j,str1,str2)){
                if(j-i+1<ans){
                    ans=j-i+1;
                    st=i;
                    en=j;
                }
                i++;
            }
            j++;
        }
        if(ans==INT_MAX){
            return "";
        }
        return str1.substr(st,ans);
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends
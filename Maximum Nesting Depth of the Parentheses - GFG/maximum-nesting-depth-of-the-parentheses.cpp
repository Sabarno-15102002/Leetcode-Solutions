//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) {
        // code here
         int max=0;
        int temp=0;
        int n=s.size();
        for (int i=0;i<n;i++){
            if (s[i]=='('){
                temp++;
            }
            else if (s[i]==')'){
                if (temp>max){
                    max=temp;
                    
                }
                temp--;
            }
        }
        return max;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
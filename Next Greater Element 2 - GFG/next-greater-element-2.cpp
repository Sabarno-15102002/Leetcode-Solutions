//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int N, vector<int>& arr) {
        // code here
        stack<int> s;
        vector<int> ans(N);
        
        for(int j=0; j<2; j++)
        {
            for(int i=N-1; i>=0; i--)
            {
                if(s.empty()) ans[i] = -1;
                else
                {
                    while(!s.empty() && arr[i]>=s.top())
                    {
                        s.pop();
                    }
                    ans[i] = s.empty() ? -1 : s.top();
                }
                s.push(arr[i]);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
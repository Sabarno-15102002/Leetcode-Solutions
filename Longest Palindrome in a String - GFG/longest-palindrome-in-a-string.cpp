//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        string t;
        t.push_back('#');
        for (int i = 0; i < s.size(); i++)
        {
            t.push_back(s[i]);
            t.push_back('#');
        }

        swap(s, t);
        int n = s.size();
        vector<int> p(n);

        // Manacher's Algorithm
        int l = 0, r = -1;
        for (int i = 0; i < n; i++)
        {
            int k;
            if (i > r)
                k = 1;
            else
                k = min(p[i], r - l);

            // for checking for palindrome
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k])
                k++;

            p[i] = k;

            // expasion of palindrome is more than the previous boundary
            if (i + k > r)
            {
                // new left and right boundary
                l = i - k;
                r = i + k;
            }
        }

        // for getting the ans
        int mx = 0, idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (p[i] > mx)
            {
                mx = p[i];
                idx = i;
            }
        }

        string cur = s.substr(idx - mx + 1, 2 * p[idx] - 1);
        string ans;
        for (auto i : cur)
            if (i != '#')
                ans.push_back(i);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
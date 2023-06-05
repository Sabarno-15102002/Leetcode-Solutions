//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& A, int k) {
        // Code here
        int low = 0,high = N-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(A[mid] == k) return 1;
            if(A[mid] == A[low]){
                low += 1;
                continue;
            }
            if(A[mid] == A[high]){
                high -= 1;
                continue;
            }
            if(A[low] <= A[mid]){
                if(k >= A[low] and k < A[mid]) high = mid-1;
                else low = mid+1;
            }
            else{
                if(k > A[mid] and k <= A[high]) low = mid+1;
                else high = mid-1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends
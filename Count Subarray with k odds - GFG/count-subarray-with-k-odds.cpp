//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    int atMost(vector<int> &A, int k){
        int i = 0 , n = A.size() , ans = 0;
        int countOdd = 0;
        for(int j=0 ; j<n ; j++ ){
            countOdd += A[j]%2 ;
            while( countOdd > k){
                countOdd -= A[i]%2 ;
                i++;
            }
            ans += j-i+1  ;
        }
        return ans;
    }

  public:
    int countSubarray(int n, vector<int>& nums, int K) {
        return atMost(nums, K) - atMost(nums , K-1);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends
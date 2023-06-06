//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int noOfbouquetWithMidAsBloomDay(vector<int> bloomDay,int M,int K,int mid)
    {
        int count=0;
        for(int i=0;i<bloomDay.size();i++)
        {  int adjflower;
          if(bloomDay[i]>mid)adjflower=0;
          
           else if(bloomDay[i]<=mid)
            {
              adjflower++;
                if(adjflower==K)
                 {
                     adjflower=0;
                     count++;
                     
                 }
            }
        }
        return count;
    }
    int solve(int M, int K, vector<int> &bloomDay){
        if(bloomDay.size()<M*K) return -1 ; 
        int low=INT_MAX,high=INT_MIN;
        
        for(int i=0;i<bloomDay.size();i++)
        {
          low=min(low,bloomDay[i]);
          high=max(high,bloomDay[i]);
        }
        
        while(low<=high)
        {
        int mid=(low+high)/2;
        
        if(noOfbouquetWithMidAsBloomDay(bloomDay,M,K,mid)<M)
        low=mid+1;
        else
        high=mid-1;
        
        }
        return low;
      
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends
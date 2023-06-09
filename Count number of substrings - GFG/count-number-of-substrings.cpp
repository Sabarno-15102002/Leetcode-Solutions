//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int substrCount (string s, int k) {
    	//code here.
    	long long int out = 0 ;
    	int n = s.length() ;
    	int low=-1 , high=-1 ;
    	
    	vector<int> lowchar(26,0);int lowcnt=0 ;
    	vector<int> highchar(26,0);int highcnt=0 ;
    	
    	for(int i=0 ; i<n ; i++)
    	{
    	    while(low < n && lowcnt < k)
    	    {
    	        low++ ;
    	        lowchar[s[low]-'a']++ ;
    	        if(lowchar[s[low]-'a']==1) lowcnt++ ;
    	    }
    	    while(high < n && highcnt <= k)
    	    {
    	        high++ ;
    	        highchar[s[high]-'a']++ ;
    	        if(highchar[s[high]-'a']==1) highcnt++ ;
    	    }
    	    
    	    out += (high-low) ;
    	    
    	    //cout << low << ' ' << high << endl ;
    	    
    	    lowchar[s[i]-'a']-- ;
    	    if(lowchar[s[i]-'a']==0) lowcnt-- ;
    	    
    	    highchar[s[i]-'a']-- ;
    	    if(highchar[s[i]-'a']==0) highcnt-- ;
    	    
    	}
    	
    	return out ;
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends
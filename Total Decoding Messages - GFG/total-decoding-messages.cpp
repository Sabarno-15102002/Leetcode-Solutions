//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int mod = 1e9+7;
    	int CountWays(string s){
            int n = s.length();
            
            if(s == "") return 1;
            if(s[0] == '0') return 0;
            
            int a = 1 , b = 1 , c;
            if(n == 1) return 1;
            
            for(int ind = 2;ind<=n;ind++)
            {
                int ans = 0;
                if(stoi(s.substr(ind-1,1)) <= 26 && stoi(s.substr(ind-1,1)) >= 1){
                    ans = a;
                }
                
                if(stoi(s.substr(ind-2,2)) <= 26 && stoi(s.substr(ind-2,2)) >= 1 && s[ind-2] > '0'){
                    ans += b;
                }
                
                c = ans % mod;
                b = a;
                a = c;
            }
            
            return c % mod;
        }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
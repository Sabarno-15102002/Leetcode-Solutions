//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		void generateAllSubsequence(int index,string s,string &subseq,vector<string> &ans) {
	        if(index == s.size()) {
	            if(subseq.size()) {
	                ans.push_back(subseq);
	            }
	            return;
	        }
	        
	        //picking up the element
	        subseq.push_back(s[index]);
	        generateAllSubsequence(index+1,s,subseq,ans);
	        
	        //not picking the element
	        subseq.pop_back();
	        generateAllSubsequence(index+1,s,subseq,ans);
	        
	    }
	
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    string subseq;
		    generateAllSubsequence(0,s,subseq,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends
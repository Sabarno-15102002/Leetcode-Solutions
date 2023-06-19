// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        int c=0;
        int ans = INT_MIN;
        int ind=-1;
        vector<int>vec(26,-1);
        
        for(int i=0;i<S.length();i++)
        {
            if(vec[S[i]-'a']==-1 || ind>vec[S[i]-'a'])
            {
                vec[S[i]-'a']=i;
                c++;
                ans = max(c,ans);
            }
            else if(vec[S[i]-'a']!=-1)
            {
                int num = vec[S[i]-'a'];
                ind = num;
                int sum = i-num;
                ans = max(ans,c);
                c=sum;
                vec[S[i]-'a']=i;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}  // } Driver Code Ends
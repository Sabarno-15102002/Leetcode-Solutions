//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string S, int N)
    {
        // your code here
        vector<int> freq(26, 0);
        for(auto i : S)
            freq[i-'a']++;
        vector<pair<char, int>> vow, cons;
        
        set<char> v = {'a', 'e', 'i', 'o', 'u'};
        int sumv = 0, sumc = 0;
        for(int i = 0 ; i < 26 ; i++)
        {
            if(freq[i] == 0)
                continue;
            char ch = (i + 'a');
            if(v.count(ch))
            {
                vow.push_back({ch, freq[i]});
                sumv += freq[i];
            }
            else
            {
                cons.push_back({ch, freq[i]});
                sumc += freq[i];
            }
        }
        
        if(abs(sumv - sumc) > 1)
            return "-1";
        string ans = "";
        if(sumv > sumc or (sumv == sumc  and vow[0].first < cons[0].first))
        {
            int i = 0, j = 0, turn = 0;
            while(N--)
            {
                if(turn == 0)
                {
                    if(vow[i].second == 0)
                        i++;
                    ans += vow[i].first;
                    vow[i].second--;
                    turn = 1 - turn;
                }
                else
                {
                    if(cons[j].second == 0)
                        j++;
                    ans += cons[j].first;
                    cons[j].second--;
                    turn = 1 - turn;
                }
            }
        }
        else
        {
            int i = 0, j = 0, turn = 1;
            while(N--)
            {
                if(turn == 0)
                {
                    if(vow[i].second == 0)
                        i++;
                    ans += vow[i].first;
                    vow[i].second--;
                }
                else
                {
                    if(cons[j].second == 0)
                        j++;
                    ans += cons[j].first;
                    cons[j].second--;
                }
                turn = 1 - turn;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
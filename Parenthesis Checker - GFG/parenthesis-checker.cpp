//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool check(char x, char y)
    {
        if(x == '(' && y == ')')
        {
            return true;
        }
        else if(x == '{' && y == '}')
        {
            return true;
        }
        else if(x == '[' && y == ']')
        {
            return true;
        }
        return false;
    }
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        for(int i = 0; i < x.size(); i++)
        {
            if(x[i] == '(' || x[i] == '{' || x[i] == '[')
            {
                st.push(x[i]);
            }
            else if(x[i] == ')' || x[i] == '}' || x[i] == ']')
            {
                if(!st.empty()){   
                    char c = st.top();
                    if(!check(c,x[i]))
                    {
                        return false;
                    }
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        
        if(!st.empty())
        {
            return false;
        }
        
        return true;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
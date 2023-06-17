//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    bool fun(char a, char b)
    {
        int ele1=0;
        
        if(a=='+' || a=='-')
        ele1=1;
        else if(a=='*' || a=='/')
        ele1=2;
        else if(a=='^')
        ele1=3;
        
        int ele2=0;
        if(b=='+' || b=='-')
        ele2=1;
        else if(b=='*' || b=='/')
        ele2=2;
        else if(b=='^')
        ele2=3;
        
        if(ele1>=ele2)
        return true;
        else
        return false;
        
    }
    string infixToPostfix(string s) 
    {
        string ans;
        stack<char>temp;
        int i=0;
        while(i<s.size())
        {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
            {
                ans.push_back(s[i]);
            }
            else 
            {
                if(temp.size()==0)
                {
                    temp.push(s[i]);
                }
                else
                {
                    if(s[i]==')')
                    {
                        while(!temp.empty() && temp.top()!='(')
                        {
                            ans.push_back(temp.top());
                            temp.pop();
                        }
                        temp.pop();
                     }
                     else if(s[i]=='(')
                     {
                         temp.push(s[i]);
                     }
                     else
                     {
                         while(!temp.empty())
                         {
                             bool flag=fun(temp.top(),s[i]);
                             if(flag)
                             {
                                 ans.push_back(temp.top());
                                 temp.pop();
                             }
                             else
                             {
                                 break;
                             }
                         }
                         temp.push(s[i]);
                     }
                }
            }
            i++;
        }
                while(!temp.empty())
        {
            ans.push_back(temp.top());
            temp.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends
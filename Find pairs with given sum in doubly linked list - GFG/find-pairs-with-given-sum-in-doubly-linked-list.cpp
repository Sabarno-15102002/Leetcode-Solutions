//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


// } Driver Code Ends
//User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        Node* idx1=head;
        Node* idx2=head;
        while(idx2->next){
            idx2=idx2->next;
        }
        vector<pair<int, int>>v;
        
  //both coditions are such that they don't cross each other;
        while(idx1!=idx2 && idx2!=idx1->prev){
            if((idx1->data + idx2->data )==target){
            v.push_back({idx1->data, idx2->data});
            idx1=idx1->next;
            idx2=idx2->prev;
        }
            
            else if(target>(idx1->data + idx2->data)){idx1=idx1->next;}
            
            else if(target<(idx1->data + idx2->data)){idx2=idx2->prev;}
        }
        
        return v; 
     
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
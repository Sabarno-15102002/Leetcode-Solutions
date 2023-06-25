//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    unordered_map<int,vector<int>> m;
    int idx;
    Node* solve(int lb,int ub,int in[],int pre[],int n){
        if(lb>ub or idx>=n) return NULL;
        int element = pre[idx++];
        Node* res = new Node(element);
        if(lb==ub) return res;
        int pos = -1;
        if(m[element][0] != INT_MIN){
            pos = m[element][0];
            m[element][0] = INT_MIN;
        }
        else {
            pos = m[element][1];
            m[element][1] = INT_MIN;
        }
        res->left = solve(lb,pos-1,in,pre,n);
        res->right = solve(pos+1,ub,in,pre,n);
        return res;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        idx = 0;
        m.clear();
        for(int i=0;i<n;i++){
            m[in[i]].push_back(i);
        }
        Node* res = solve(0,n-1,in,pre,n);
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends
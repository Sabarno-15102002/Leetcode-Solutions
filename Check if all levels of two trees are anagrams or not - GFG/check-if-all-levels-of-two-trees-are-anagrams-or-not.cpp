//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool check(vector<int>arr1,vector<int>arr2)

    {

    int N=arr1.size();

    int M=arr2.size();

    

    if (N != M)

        return false;

 

    sort(arr1.begin(), arr1.end());

    sort(arr2.begin(), arr2.end());

 

    for (int i = 0; i < N; i++)

        if (arr1[i] != arr2[i])

            return false;

 

    return true;

}

    

    bool areAnagrams(Node *root1, Node *root2)

    {

        queue<Node*>q;

        q.push(root1);

        vector<vector<int>>ans1;

 

        while(!q.empty()){

            vector<int>temp;

            int n=q.size();

            for(int i=0;i<n;i++){

                Node* ele=q.front();

                q.pop(); 

                temp.push_back(ele->data);

                if(ele->left)q.push(ele->left);

                if(ele->right)q.push(ele->right);

            }

            ans1.push_back(temp);

        }

        

        

        queue<Node*>p;

        p.push(root2);

        vector<vector<int>>ans2;

 

        while(!p.empty()){

            vector<int>temp;

            int n=p.size();

            for(int i=0;i<n;i++){

                Node* ele=p.front();

                p.pop(); 

                temp.push_back(ele->data);

                if(ele->left)p.push(ele->left);

                if(ele->right)p.push(ele->right);

            }

            ans2.push_back(temp);

        }

        

        if(ans1.size() != ans2.size())return false;

        

        for(auto i=0;i<ans1.size();i++){

            if(!check(ans1[i],ans2[i])){

                return false;

            }

        }

        return true;

    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends
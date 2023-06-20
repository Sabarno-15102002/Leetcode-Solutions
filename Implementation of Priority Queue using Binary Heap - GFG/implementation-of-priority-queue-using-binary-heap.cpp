//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int H[10009];
int s = -1;
int parent(int i) {
    return (i - 1) / 2;
}
int leftChild(int i) {
    return ((2 * i) + 1);
}
int rightChild(int i) {
    return ((2 * i) + 2);
}
void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}
void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);

    if (l <= s && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);

    if (r <= s && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}
void insert(int p) {
    s = s + 1;
    H[s] = p;
    shiftUp(s);
}

// } Driver Code Ends
// User function Template for C++
// 1. parent(i): Function to return the parent node of node i
// 2. leftChild(i): Function to return index of the left child of node i
// 3. rightChild(i): Function to return index of the right child of node i
// 4. shiftUp(int i): Function to shift up the node in order to maintain the
// heap property
// 5. shiftDown(int i): Function to shift down the node in order to maintain the
// heap property.
// int s=-1, current index value of the array H[].

class Solution {
  public:
    int extractMax() {
        // your code here
        int li = s; //lastIndex in the heap
        if(li == -1) return 0; //indicating no elements in heap, so no max
        
        int ans = H[0]; //storing max element of heap to return
        
        s--; //removing last element from the heap
        
        //down heapify process now
        swap(H[0] , H[li]); //swapping first and last index in heap
        int parentIndex = 0; //parentIndex (Index of element to be assigned in heap)
        int leftIndex = (2 * parentIndex) + 1;
        int rightIndex = (2 * parentIndex) + 2;
        
        while(leftIndex <= s)
        {
            //holds the index of maximum element between above three elements
            int maxIndex = parentIndex; //initialised to parentIndex
            if(H[leftIndex] > H[maxIndex]) maxIndex = leftIndex;
            if(H[rightIndex] > H[maxIndex] && rightIndex <= s) maxIndex = rightIndex; 
            
            if(maxIndex == parentIndex) break; //correct position reached so break
            swap(H[parentIndex], H[maxIndex]);
            
            //updating for next Iteration
            parentIndex = maxIndex;
            leftIndex = (2 * parentIndex) + 1;
            rightIndex = (2 * parentIndex) + 2;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            insert(k);
        }

        Solution ob;

        cout << "Node with maximum priority : " << ob.extractMax() << "\n";
        cout << "Priority queue after "
             << "extracting maximum : ";
        int j = 0;
        while (j <= s) {
            cout << H[j] << " ";
            j++;
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
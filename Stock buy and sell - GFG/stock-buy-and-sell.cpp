//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    // code here
    vector<pair<int , int>> v;
    for(int i = 0 ; i< n-1 ; i++){
        if(price[i+1] > price[i]){
            int buy = i, sell = i;
            while(sell<n-1 && price[sell] < price[sell+1]){
                sell++;
            }
            if(sell>buy){
                v.push_back({buy,sell});
            }
            i = sell;
        }
    }
    if(v.empty())
    cout<<"No Profit";
    else{
        for(auto p : v){
            cout<<"("<<p.first<<" "<<p.second<<") ";
        }
    }
    cout<<"\n";
}
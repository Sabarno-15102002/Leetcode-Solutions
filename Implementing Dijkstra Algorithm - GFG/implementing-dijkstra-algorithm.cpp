//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
       
        // a vector storing shortest distance of each node from vertex
        vector<int>dist(V,INT_MAX);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
 
        dist[S]=0;
// TAKING DISTANCE OF SOURCE IS EQUAL TO 0
       
        pq.push({0, S});
  //PUSHING VALUE OF DISTANCE ALONG WITH RANDOM CURRENT NODE
        
        while(!pq.empty()){
            int node=pq.top().second;  // current node
            int dis=pq.top().first;
            pq.pop();//distance or wieght of that node
            
            for(auto it : adj[node]){
                int adjnode=it[0];  // this means we are taking elemetnt 2nd of {1,3} which is itself a node[0] for source 2 
                int adjweight=it[1];  
                
                if(dis + adjweight < dist[adjnode]) {
                    dist[adjnode]=dis + adjweight;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        
        return dist;
       
    }
};



//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
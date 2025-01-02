//NOTE: THE WEIGHTS MUST BE POSITIVE!!!

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9+10;

vector<pair<int, int>> G[N];//<node, weight>

void dijkstra(int vertex){
    vector<int> vis(N, 0);
    vector<int> dist(N, INF);

    set<pair<int, int>> st;//<weight, node>

    dist[vertex] = 0;
    st.insert({dist[vertex], vertex});
    
    while(!st.empty()){
        auto node = *st.begin();
        int distance = node.first;
        int v = node.second;

        st.erase(st.begin());

        if(vis[v]) continue;
        vis[v] = 1;

        for(auto child: G[v]){
            int childV = child.first;
            int childDist = child.second;
            
            if(dist[v] + childDist < dist[childV]){
                dist[childV] = dist[v] + childDist;
                st.insert({dist[childV], childV});
            }
        
        }
    }

}

int main() {
    // Your code goes here
    int v, e;
    cout << "\nEnter number of Vertices and Edges: ";
    cin >> v >> e;
    while(e){
        cout << "\nEnter the connected vertices as well as their weights through which they are connected: ";
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        G[v1].push_back({v2, weight});
        // G[v2].push_back({v2, -weight}); Directed Graph doesn't need this!
        e--;
    }

    
    return 0;
} 
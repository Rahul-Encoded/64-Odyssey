#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

vector<int> g[N];
bool vis[N];

/*
     0
    /|\
   1-2-3
     \|/
      4
     / \
    5   6

*/

void dfs(int vertex) {
    // Take action on vertex after entering the vertex
    // if(vis[vertex]) return = if(vis[vertex]) continue;
    cout << "Vertex: " << vertex << endl;
    vis[vertex] = true;
    for(auto &child : g[vertex]) {
        cout << "parent: " << vertex << ", child: " << child << endl;
        if(vis[child]) continue;
        // Take action on child before entering the child node
        dfs(child);
        // Take action on child after exiting the child node
    }
    // Take action on vertex before exiting the vertex
}
// O(V+E)

int main() {
    int n, m;
    cout << "Enter # of vertices and edges: ";
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int v1, v2;
        cout << "\nEnter the connected vertices: ";
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    
    // for(int i = 1; i <= n; i++) {
    //     if(vis[i]) continue;
    //     dfs(i);
    //     EITHER OF THESE WORKS IF & ONLY IF THERE IS 1 SINGLE GRAPH WITHOUT ANY DISCONNECTION
    // }
    /*
    
    Vertex: 1
    parent: 1, child: 2
    Vertex: 2
    parent: 2, child: 1
    parent: 2, child: 5
    Vertex: 5
    parent: 5, child: 2
    parent: 2, child: 6
    Vertex: 6
    parent: 6, child: 2
    parent: 1, child: 3
    Vertex: 3
    parent: 3, child: 1
    parent: 1, child: 4
    Vertex: 4
    parent: 4, child: 1
    parent: 4, child: 7
    Vertex: 7
    parent: 7, child: 4    
    
    */

    dfs(1);
    /*

    Vertex: 1
    parent: 1, child: 2
    Vertex: 2
    parent: 2, child: 1
    parent: 2, child: 5
    Vertex: 5
    parent: 5, child: 2
    parent: 2, child: 6
    Vertex: 6
    parent: 6, child: 2
    parent: 1, child: 3
    Vertex: 3
    parent: 3, child: 1
    parent: 1, child: 4
    Vertex: 4
    parent: 4, child: 1
    parent: 4, child: 7
    Vertex: 7
    parent: 7, child: 4

    */
    
    return 0;
}

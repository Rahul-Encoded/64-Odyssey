#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

vector<int> graph[N];
bool visited[N];

//IN ORDER TO STORE CONNECTED
vector<vector<int>> connectedComponents;
vector<int> currentCC;

void dfs(int vertex){
    //
    visited[vertex] = true;
    currentCC.push_back(vertex);
    for(auto &child: graph[vertex]){
        //
        if(visited[child]) continue;
        dfs(child);
        //
    }
    //
}

//O(V+E)

int main() {
    int n, m;
    cout << "\nEnter the no. of Vertices and Edges: ";
    cin >> n >> m;
    //Adjacency List
    for(int i = 0; i < m; i++){
        int v1, v2;
        cout << "\nEnter the Vertices connected: ";
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    // int count = 0;
    for(int i = 1; i <= n; i++) {
        if(visited[i]) continue;
        currentCC.clear();
        dfs(i);
        connectedComponents.push_back(currentCC);
        // count++;
    }
    cout << "Count of connected components: " << currentCC.size() << endl;

    for(auto &cCC: connectedComponents){
        for(auto &vertex: cCC){
            cout << vertex << " ";
        }
        cout << endl;
    }
    // TO FIND CONNECTED COMPONENTS IN THE GRAPH

    return 0;
}
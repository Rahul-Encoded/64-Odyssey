#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

vector<int> g[N];
bool visited[N] = {0};
int level[N];

void bfs(int node){
    queue<int> nodes;
    visited[node] = 1;
    nodes.push(node);
    
    while(!nodes.empty()){
        cout << nodes.front() << ": " << level[nodes.front()] << endl;
        int currentNode = nodes.front();
        nodes.pop();
        for(auto &child: g[currentNode]){
            if(!visited[child]){
            nodes.push(child);
            visited[child] = 1;
            level[child] = level[currentNode] + 1; 
            }
        }
    }
}
//(O(V + (2*E)))

int main() {
    int n, edges;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int v1, v2;
        cout << "Enter the connected nodes (parent and child): ";
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    int startNode;
    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    bfs(startNode);

    return 0;
}
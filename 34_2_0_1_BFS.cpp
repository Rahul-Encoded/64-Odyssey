//0-1 BFS
/*
A directed graph with N vertices and M edges is given.
What is the minimum number of edges he needs to reverse in order to have at least one path from vertex 1 to vertex N, where the vertices are numbered from 1 to N?
1 ≤ N,M ≤ 10^5
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int INF = 1e9+10;

vector<pair<int, int>> g[N];
vector<int> dist(N, INF);
int n, m;

int bfs(int vertex){
    deque<int> q;
    q.push_back(vertex);
    dist[vertex] = 0;

    while(!q.empty()){
        int currentV = q.front();
        q.pop_front();
        
        for(auto &child: g[currentV]){
            int childV = child.first;
            int childWeight = child.second;
            if(dist[currentV] + childWeight < dist[childV]){
                dist[childV] = dist[currentV] + childWeight;
                if(childWeight) q.push_back(childV);
                else q.push_front(childV);
            }
        }
    }
    return dist[n] == INF ? -1 : dist[n];
}

int main() {
    // Your code goes here
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        int v1, v2;
        cout << "Enter the connected nodes (parent -> child)(Directed): ";
        cin >> v1 >> v2;
        if(v1 == v2) continue;
        g[v1].push_back({v2, 0});
        g[v2].push_back({v1, 1});   //reverse edges we are putting... This is not given in the question
    }

    cout << bfs(1) << endl;

    return 0;
}
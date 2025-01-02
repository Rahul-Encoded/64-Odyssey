#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

vector<int> graph[N];
bool visited[N];


bool dfs(int vertex, int pre = 0){
    //
    visited[vertex] = true;
    bool loopExists = false;

    for(auto &child: graph[vertex]){
        //
        if(visited[child] && child == pre) continue;
        if(visited[child]) return true;
        
        loopExists |= dfs(child, vertex);
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

    bool loopExists = false;
    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        // loopExists |= dfs(vertex)
        if(dfs(i)){
            loopExists = true;
            break;
        }
    }

    (loopExists) ? (cout << "There exists a Loop in the Graph!!!") : (cout << "There DOES NOT EXIST a Loop in the Graph!!!");

    return 0;
}
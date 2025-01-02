#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

vector<int> g[N];
int depth[N], height[N];

void dfs(int vertex, int parent=0){
    //going down
    for(int child: g[vertex]){
        //going down, before entering child
        if(child == parent) continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        //going up, after exiting child
        height[vertex] = max(height[vertex], height[child]+1);
    }
    //going up
}

int main() {
    // Your code goes here
    int n;
    cout << "Enter # of nodes: ";
    cin >> n;
    for(int i = 0; i < n-1/*edges*/; i++) {
        int v1, v2;
        cout << "\nEnter the connected nodes(parent and child): ";
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    dfs(1);
    cout << "\ndepth-height" << endl;
    for(int i = 1; i <= n; i++){
        cout << depth[i] << "      " << height[i] << endl; 
    }

    return 0;
}
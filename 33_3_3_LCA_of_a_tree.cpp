#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

vector<int> g[N];
int par[N];

void dfs(int vertex, int parent=0){
    //going down
    par[vertex] = parent; 
    for(int child: g[vertex]){
        //going down, before entering child
        if(child == parent) continue;
        dfs(child, vertex);
        //going up, after exiting child
    }
    //going up
}

vector<int> path(int v){
    vector<int> ans;
    while(v != 1){
        ans.push_back(v);
        v = par[v];
    }
    reverse(ans.begin(), ans.end());
    return ans;
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

    int x, y;
    cout << "\nProvide 2 nodes: ";
    cin >> x >> y;
    vector<int> path_x = path(x);
    vector<int> path_y = path(y);
    int minLen = min(path_x.size(), path_y.size());

    int lca = -1;
    for(int i = 0; i < minLen; i++){
        if(path_x[i] == path_y[i]){
            lca = path_x[i];
        }
        else{
            break;
        }
    }

    cout << "\nLCA of th 2 provided nodes: " << lca;

    return 0;

}
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

/*
Given Q Queries, Q <= 10^5
In each query given V,
Print subtree Sum of V and Number of even numbers
in a subtree of V
*/

vector<int> g[N];
int subtreeSum[N], evenCount[N];

void dfs(int vertex, int parent = 0) {
    // going down
    subtreeSum[vertex] = vertex; // Initialize the subtree sum with the vertex value
    if(vertex % 2 == 0) evenCount[vertex]++; // Check if the vertex value is even
    for(int child: g[vertex]) {
        // going down, before entering child
        if(child == parent) continue;

        dfs(child, vertex);
        // going up, after exiting child
        subtreeSum[vertex] += subtreeSum[child];
        evenCount[vertex] += evenCount[child];
    }
    // going up
}

int main() {
    // Your code goes here
    int n;
    cout << "Enter # of nodes: ";
    cin >> n;
    for(int i = 0; i < n - 1; i++) { // n-1 edges
        int v1, v2;
        cout << "\nEnter the connected nodes (parent and child): ";
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    dfs(1);

    int q;
    cout << "Enter # of queries: ";
    cin >> q;
    while(q--) {
        int v;
        cout << "\nEnter Vertex: ";
        cin >> v;
        cout << "\nSubtree Sum = " << subtreeSum[v];
        cout << "\nEven Count = " << evenCount[v];
    }

    return 0;
}

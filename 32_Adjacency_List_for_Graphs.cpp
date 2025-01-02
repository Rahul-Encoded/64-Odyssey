// n = No. of Vertices
// m = No. of Edges
// Vi - Vj --> Connection between 2 vertices

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<pair<int, int>> graph[N]; 

int main() {
    int n, m;
    cout << "Enter the number of Vertices and Edges you wish to enter: ";
    cin >> n >> m;

    cout << "\nEnter the vertices which are connected to each other:";
    for (int i = 0; i < m; i++) {
        int v1, v2, weight;
        cout << "\nEnter vertex 1, vertex 2, and the weight of the connection (space-separated): ";
        cin >> v1 >> v2 >> weight;
        graph[v1].push_back({v2, weight});
        graph[v2].push_back({v1, weight});
    }
    //Remember even though I have not put any constraints regarding the values of v1 and v2 here... 
    //v1 and v2 should be less than n!!!

    cout << "\nAdjacency List:\n";
    for (int i = 1; i <= n; i++) {
        cout << "Vertex " << i << ":";
        for(auto &edge: graph[i]){
            cout << " (" << edge.first << ", " << edge.second << " )\n";
        }
        cout << "\n";
    }

    return 0;
}

// Space Complexity = O(N + M)
//N = 10^5
//Edges should be < 10^7
//In order to check if 2 vertices are connected, Adj. List takes O(N) Time complexity
//for(pair<int, int> child: graph[i]){
    //return (child.first == j) ? child.second : 0;
    //}




// n = No. of Vertices
// m = No. of Edges
// Vi - Vj --> Connection between 2 vertices

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int graph[N][N]; 

int main() {
    int n, m;
    cout << "Enter the number of Vertices and Edges you wish to enter: ";
    cin >> n >> m;

    cout << "\nEnter the vertices which are connected to each other:";
    for (int i = 0; i < m; i++) {
        int v1, v2, weight;
        cout << "\nEnter vertex 1, vertex 2, and the weight of the connection (space-separated): ";
        cin >> v1 >> v2 >> weight;
        graph[v1][v2] = weight;
        graph[v2][v1] = weight;
    }
    //Remember even though I have not put any constraints regarding the values of v1 and v2 here... 
    //v1 and v2 should be less than n!!!

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

// Space Complexity = O(N^2)
// Therefore we can't store graph more than 10^4*10^4,
// since maximum limit of contiguous memory which can be allocated is 10^8.
//In order to check if 2 vertices are connected, Adj. Matrix takes O(1) Time complexity
//return (graph[i][j] == 1) ? weight : 0;

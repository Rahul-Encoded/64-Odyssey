/*
Snakes and transition from Capitalism to Socialism

After a long duration of the painful, torturous and tumultuous periods of capitalism in Snakeland, now the snakes have decided to adopt socialism. The houses in Snakeland are arranged in a rectangular fashion of dimension n * m. The wealth of the snake in the house at cell (i, j) is given by a[i][j] rupees.

A bill has been passed for making a smooth transition from capitalism to socialism. At the end of each hour, the wealth of a snake will grow and will become equal to the highest wealth that its neighbor had (at the start of the hour). That is, consider the maximum wealth among its neighbors at the start of the hour, and this snake's wealth will become equal to that at the end of the hour. Note that this increase in wealth will happen simultaneously for each snake. Two houses are said to be neighbors of each other if they share a side or corner with each other. Find out the minimum number of hours required for this transition.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains two space separated integers: n, m.

Each of the next n lines contains m space separated integers. The j-th integer in the i-th row denotes a[i][j].

Output
For each test case output a single integer corresponding to the minimum number of hours required for the transition.

Constraints
1 ≤ T ≤ 4
1 ≤ n, m ≤ 500
1 ≤ a[i][j] ≤ 106
Example
Input
3
2 2
1 1
1 1
2 2
1 1
1 2
3 4
1 2 1 2
1 1 1 2
1 1 2 2
Output
0
1
2

Explanation
Example 1. The wealth of all the snakes is already equal. So, no time is required for the transition.

Example 2. At the end of the first hour, the wealth of snakes at cells (1, 1), (2,1) and (1, 2) will change from 1 to 2. Then, the wealth of all the snakes becomes equal, and hence it required a total of 1 hour.

Example 3. At the end of the first hour, the distribution of wealth of Snakeland will be as given below:

2 2 2 2
2 2 2 2
1 2 2 2
After the end of the second hour, the wealth of all the snakes will be equal. So, the answer is 2.
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
const int INF = 1e9+10;

int val[N][N];
int vis[N][N];
int lev[N][N];
int n, m;

// All possible moves 
vector<pair<int, int>> possibleMoves = {
    {-1, 0}, {1, 0},
    {0, 1}, {0, -1},
    {1, 1}, {1, -1},
    {-1, 1}, {-1, -1}
};

// Function to check if a position is valid within the matrix boundaries
bool isValid(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

int bfs(){
    int mx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mx = max(mx, val[i][j]);
        }
    }
    
    queue<pair<int, int>> q;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mx == val[i][j]){
                q.push({i, j});
                lev[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    int ans = 0;

    while(!q.empty()){
        auto v = q.front();
        int vx = v.first;
        int vy = v.second;
        q.pop();

        for(auto movement: possibleMoves){
            int childx = movement.first + vx;
            int childy = movement.second + vy;
            if(!isValid(childx, childy)) continue;
            if(vis[childx][childy]) continue;
            q.push({childx, childy});
            lev[childx][childy] = lev[vx][vy] + 1;
            vis[childx][childy] = 1;
            ans = max(ans, lev[childx][childy]);
        }
    }
}

void reset(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            vis[i][j] = 0;
            lev[i][j] = INF;
        }
    }
}

int main() {
    // Your code goes here
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        reset();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> val[i][j];
            }
        }
        cout << bfs() << endl;
    }
    return 0;
}
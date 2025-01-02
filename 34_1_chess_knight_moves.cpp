#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int visited[8][8];
int level[8][8];

// Function to convert the first character of the position to the x-coordinate
int getX(string s) {
    return s[0] - 'a';
}

// Function to convert the second character of the position to the y-coordinate
int getY(string s) {
    return s[1] - '1';
}

// All possible moves of a knight in chess
vector<pair<int, int>> possibleMoves = {
    {-1, 2}, {1, 2},
    {-1, -2}, {1, -2},
    {-2, 1}, {2, 1},
    {-2, -1}, {2, -1}
};

// Function to check if a position is valid within the chessboard boundaries
bool isValid(int x, int y) {
    return (x >= 0 && y >= 0 && x < 8 && y < 8);
}

// Function to perform BFS and find the minimum number of moves from start to destination
int bfs(string start, string destination) {
    int startX = getX(start);
    int startY = getY(start);
    int destinationX = getX(destination);
    int destinationY = getY(destination);

    if (startX == destinationX && startY == destinationY) {
        return 0; // If the start and destination are the same
    }

    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = 1;

    while (!q.empty()) {
        pair<int, int> currentPos = q.front();
        int x = currentPos.first;
        int y = currentPos.second;
        q.pop();

        for (auto move : possibleMoves) {
            int childX = move.first + x;
            int childY = move.second + y;
            if (!isValid(childX, childY)) continue;
            if (!visited[childX][childY]) {
                q.push({childX, childY});
                level[childX][childY] = level[x][y] + 1;
                visited[childX][childY] = 1;
                if (childX == destinationX && childY == destinationY) {
                    return level[childX][childY]; // Early exit if destination is reached
                }
            }
        }
    }
    return level[destinationX][destinationY];
}

// Function to reset the visited and level arrays for the next test case
void reset() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            visited[i][j] = 0;
            level[i][j] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        reset();
        string s1, s2;
        cin >> s1 >> s2;
        cout << bfs(s1, s2) << endl; // Print the result for each test case on a new line
    }
    return 0;
}

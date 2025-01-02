#include <stdio.h>

/*
     0
    /|\
   1-2-3
     \|/
      4
     / \
    5   6

*/

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
};

void dfs(int vertex){
    printf("%d ", vertex);
    visited[vertex] = 1;
    //
    for(int child = 0; child < 7; child++){
        //
        if(a[vertex][child] && !visited[child]){
            dfs(child);
        }
        //
    }
    //
}

int main() {
    // Your code goes here
    dfs(1);
    return 0;
}
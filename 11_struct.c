#include <stdio.h>

struct player
{
    char name[25];
    int score;
};

int main()
{
    // struct = collection of related members (variables)
    //          they can be of different data types
    //          listed under one name in a block of code
    //          very similar to classes in other languages (but no methods)

    struct player player1;
    struct player player2;
/*
    strcpy(player1.name, "ViratKohli");
    player1.score = 101;

    strcpy(player2.name, "RohitSharma");
    player2.score = 131;
*/
    printf("Enter player #1's name : ");
    fgets(player1.name, sizeof(player1.name), stdin);
    
    printf("Enter player #2's name : ");
    fgets(player2.name, sizeof(player2.name), stdin);

    printf("Enter player #1's score : ");
    scanf("%d", &player1.score);

    printf("Enter player #2's score : ");
    scanf("%d", &player2.score);

    printf("%s", player1.name);
    printf("%d", player1.score);

    printf("\n%s", player2.name);
    printf("%d", player2.score);

    return 0;
}
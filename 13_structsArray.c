#include <stdio.h>

struct mc
{
    char name[25];
    float power;
    int age;
};

int main ()
{
    struct mc mc1 ={"Goku", 9e9, 39};
    struct mc mc2 = {"Vegeta", 8e9, 45};
    struct mc mc3 = {"Gohan", 7.69e9, 21};
    struct mc mc4 = {"Goten", 6.9e8, 7};
    struct mc mc5 = {"Trunks", 6.88e8, 8};

    struct mc mcs[] = {mc1, mc2, mc3, mc4, mc5};

    for (int i = 0; i < sizeof(mcs)/ sizeof(mcs[0]); i++)
    {
        printf("Main Character name : %s\nMain Character Power level : %f\nMain Character age : %d\n", mcs[i].name, mcs[i].power, mcs[i].age);
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>

using namespace std;

char string1[100];
char string2[100];

int sol[100][100];

int main()
{
    ifstream f("date.in");
    ofstream g("date.out");

    f>>string1;
    f>>string2;

    int n = strlen(string1 + 1);
    int m = strlen(string2 + 1);

    int c1, c2, c3;
    f>>c1>>c2>>c3;

    for (int i  = 1; i <= n; i++)
        sol[i][0] = sol[i-1][0] + c2;

    for (int j = 1; j <= m; j++)
        sol[0][j] = c1 + sol[0][j-1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (string1[i] == string2[j])
                sol[i][j] = sol[i-1][j-1];
            else
                sol[i][j] = min(sol[i-1][j-1] + c3, min(sol[i][j-1] + c1, sol[i-1][j] + c2));

    g<<sol[n][m];

    int poz_i = n, poz_j = m;

    do
    {
        if (string1[poz_i] == string2[poz_j])
        {
            g<<"pastram "<<string1[poz_i]<<endl;
            poz_i--;
            poz_j--;
        }
        else if (sol[poz_i][poz_j] - c3 == sol[poz_i - 1][poz_j-1])
        {
            g<<"inlocuim "<<string1[poz_i]<<"-"<<string2[poz_j]<<endl;
            poz_i--;
            poz_j--;
        }
        else if (sol[poz_i][poz_j] - c1 == sol[poz_i][poz_j - 1])
        {
            g<<"inseram "<<string2[poz_j]<<endl;
            poz_j--;
        }
        else if (sol[poz_i][poz_j] - c2 == sol[poz_i - 1][poz_j])
        {
            g<<"stergem "<<string1[poz_i]<<endl;
            poz_i--;
        }
    }
    while(poz_i > 0 && poz_j > 0);


    while(poz_i > 0)
    {
        g<<"stergem "<<string1[poz_i]<<endl;
        poz_i--;
    }

    while(poz_j > 0)
    {
        g<<"inseram "<<string2[poz_j];
        poz_j--;
    }

    return 0;
}

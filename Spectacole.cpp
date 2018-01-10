#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;


struct eveniment
{

    int inceput, sfarsit, profit;
};

eveniment v[100];
int prec[100], dp[100];
int n;

bool cmp(eveniment a, eveniment b)
{
    return a.sfarsit < b.sfarsit;
}

int main()
{

    ifstream f("date.in");
    ofstream g("date.out");

    f>>n;
    for(int i = 1; i <= n; i++)
        f>>v[i].inceput>>v[i].sfarsit>>v[i].profit;

    sort(v + 1, v + n + 1, cmp);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (v[j].sfarsit <= v[i].inceput)
                prec[i] = j;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = max (dp[i-1], dp[prec[i]] + v[i].profit);
    }

    g<<dp[n]<<endl;
    int poz = n;
    while (poz != 0)
    {
        if (dp[poz] == dp[poz-1])
            poz--;
        else
        {
            g<<v[poz].inceput<<" "<<v[poz].sfarsit<<endl;
            poz = prec[poz];
        }
    }

    return 0;
}

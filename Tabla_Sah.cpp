#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int mtx[100][100], sol[100][100];
vector <pair<int, int>> poz;


int main()
{
    ifstream f("date.in");
    ofstream g("date.out");
    int n, m;
    f>>n>>m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f>>mtx[i][j];

    for (int i = 1; i <= n; i++)
        sol[i][1] = sol[i-1][1] + mtx[i][1];

    for (int j = 1; j <= m; j++)
        sol[1][j] = sol[1][j-1] + mtx[1][j];

    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= m; j++)
            sol[i][j] = max(sol[i-1][j], sol[i][j-1]) + mtx[i][j];

    g<<sol[n][m]<<endl;

    int poz_i = n, poz_j = m;
    poz.push_back({n, m});

    do
    {


        if (sol[poz_i][poz_j] - mtx[poz_i][poz_j] == sol[poz_i-1][poz_j])
            poz_i--;
        else
            poz_j--;
        poz.push_back({poz_i, poz_j});
    }
    while (!(poz_i == 1 && poz_j == 1));

    for (int i = poz.size() - 1; i >= 0; i--)
        g<<poz[i].first<<" "<<poz[i].second<<endl;

    return 0;
}

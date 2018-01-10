#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct piesa
{
    int ps, pd;
};

int lmax[100];
vector <int> pozitii_lmax[100];
int pred[100];
piesa v[100];

int main()
{

    ifstream f("date.in");
    ofstream g("date.out");
    vector <piesa> sol;
    int lmax_sir = 1;
    int nr = n;
    int poz_lmax = 1;
    int n;
    f>>n;

    for (int i = 1; i <= n; i++)
    {
        f>>v[i].ps>>v[i].pd;
        lmax[i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {

        for (int j = i - 1; j >= 1; j--)
            if (v[j].pd == v[i].ps)
            {

                if (lmax[j] + 1 >= lmax[i])
                {
                    lmax[i] = lmax[j] + 1;
                    pred[i] = j;

                    if (lmax[i] > lmax_sir)
                    {

                        lmax_sir = lmax[i];
                        nr = 1;
                        poz_lmax = i;
                    }
                    else if (lmax[i] == lmax_sir)
                        nr ++;
                }
            }
    }
    int poz = poz_lmax;
    while (poz != 0)
    {

        sol.push_back(v[poz]);
        poz = pred[poz];
    }

    for (int i = sol.size() - 1; i >= 0; i--)
        g<<sol[i].ps<<" "<<sol[i].pd<<endl;

    g<<nr;

    return 0;
}

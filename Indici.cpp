#include <iostream>
#include <fstream>

using namespace std;

int cautare(int v[], int st, int dr)
{
    if(st<=dr)
    {
        int m=st+(dr-st)/2;
        if(m==v[m])
            return m;
        if(m>v[m])
            return cautare(v,m+1,dr);
        else
            return cautare(v,st,m-1);
    }
    return -1;
}

int main()
{
    int n, v[100];
    ifstream f("date.in");
    ofstream g("date.out");
    f>>n;
    for(int i=0;i<n;i++)
        f>>v[i];
    g<<cautare(v,0,n-1);
    return 0;
}

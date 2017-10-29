#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

struct act
{
    int l,t,poz;
};

int cmp(const void *a, const void *b)
{
    act p1=*(act*)a;
    act p2=*(act*)b;
    return p1.t-p2.t;
}

int main()
{
    int n;
    act v[100];
    f>>n;
    for(int i=1;i<=n;i++)
        {f>>v[i].l>>v[i].t;
        v[i].poz=i;}
    qsort(v+1,n,sizeof(act),cmp);
    for(int i=1;i<=n;i++)
        cout<<v[i].l<<" "<<v[i].t<<endl;
    int intarziere=0,capat=0;
    for(int i=1;i<=n;i++)
    {
        g<<"Activitatea"<<v[i].poz<<":intervalul ["<<capat<<" "<<capat+v[i].l<<")";
        capat+=v[i].l;
        g<<"Intarziere"<<capat-v[i].t<<endl;
        int aux=capat-v[i].t;
        intarziere=max(intarziere,aux);
    }
    g<<"Intarziere planificare "<<intarziere;
    return 0;
}

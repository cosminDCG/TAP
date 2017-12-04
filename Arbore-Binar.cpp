#include <iostream>
#include <fstream>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

struct nod
{
    int info;
    nod* st, *dr;
};

int cauta(int v[], int st, int dr, int x)
{
    int i;
    for(i=st;i<=dr;i++)
        if(v[i]==x)
        break;
    return i;
}

nod* construieste(int in[], int post[], int inS, int inE, int *p)
{
    if(inS>inE)
        return NULL;
    nod* q=new nod;
    q->info=post[*p];
    q->st=q->dr=NULL;
    (*p)--;
    int i=cauta(in, inS, inE, q->info);
    q->dr=construieste(in, post, i+1, inE,p);
    q->st=construieste(in, post, inS, i-1,p);
    return q;
}

nod* rezolva(int in[], int post[], int n)
{
    int p=n-1;
    return construieste(in, post, 0, n-1, &p);
}

void preordine(nod* p)
{
    if(p==NULL)
        return;
    g<<p->info<<" ";
    preordine(p->st);
    preordine(p->dr);
}
int main()
{
    int n,in[100],post[100];

    f>>n;
    for(int i=0;i<n;i++)
        f>>in[i];
    for(int i=0;i<n;i++)
        f>>post[i];
    nod *r=rezolva(in, post, n);
    preordine(r);
    return 0;
}

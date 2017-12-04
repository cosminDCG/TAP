#include <iostream>
#include <fstream>

using namespace std;

float med2(int a, int b)
{
    return (a+b)/2.0;
}

float med3(int a, int b, int c)
{
    return a+b+c-max(a, max(b,c))-min(a, min(b,c));
}

float med4(int a, int b, int c, int d)
{
    int x=max(a, max(b, max(c,d)));
    int y=min(a, min(b, min(c,d)));
    return (a+b+c+d-x-y)/2.0;
}

float medsp(int v[], int n)
{
    if(n==0)
        return -1;
    if(n%2==0)
        return (v[n/2]+v[n/2-1])/2.0;
    return v[n/2];
}

float mediana(int v[], int n, int u[], int m)
{
    if(n==0)
        return medsp(u,m);
    if(n==1)
    {
        if(m==1)
            return med2(v[0], u[0]);
        if(m%2==1)
            return med2(u[m/2],med3(v[0], u[m/2-1], u[m/2+1]));
        return med3(u[m/2], u[m/2-1],v[0]);
    }
    else if(n==2)
    {
        if(m==2)
            return med4(v[0],v[1],u[0],u[1]);
        if(m%2==1)
            return med3(u[m/2], max(v[0], u[m/2-1]), min(v[1], u[m/2+1]));
        return med4(u[m/2], u[m/2-1], max(v[0], u[m/2-2]),min(v[1], u[m/2+1]));
    }
    int x=(n-1)/2;
    int y=(m-1)/2;
    if(v[x]<=u[y])
        return mediana(v+x,n/2+1,u,m-x);
    return mediana(v,n/2+1,u+x,m-x);
}

float calcul(int v[], int n, int u[], int m)
{
    if(n>m)
        return mediana(u,m,v,n);
    return mediana(v,n,u,m);
}

int main()
{
    int v[100], u[100], n, m;
    ifstream f("date.in");
    ofstream g("date.out");
    f>>n;
    for(int i=0;i<n;i++)
        f>>v[i];
    f>>m;
    for(int i=0;i<m;i++)
        f>>u[i];
    g<<calcul(v,n,u,m);
    return 0;
}

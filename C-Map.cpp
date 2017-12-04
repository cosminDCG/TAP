#include <iostream>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

struct punct
{
    int x,y;
}sol[2];

int cmp1(const void* a, const void* b)
{
    punct *p1=(punct *)a;
    punct *p2=(punct *)b;
    return p1->x-p2->x;
}

int cmp2(const void* a, const void* b)
{
    punct *p1=(punct *)a;
    punct *p2=(punct *)b;
    return p1->y-p2->y;
}

float distanta(punct p1, punct p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +(p1.y - p2.y)*(p1.y - p2.y));
}

float det(punct a[], int k, float d)
{
    float minim=d;
    int p1, p2,p3,p4;
    qsort(a,k,sizeof(punct),cmp2);
    for(int i=0;i<k;i++)
        for(int j=i+1;j<k && (a[j].y-a[i].y)<minim;j++)
            if(distanta(a[i],a[j])<minim)
            {
                minim=distanta(a[i],a[j]);
                sol[0]=a[i];
                sol[1]=a[j];
            }
    return minim;
}

float apropiere(punct v[], int n)
{
    if(n==1)
        return -1;
    if(n==2)
    {

        return distanta(v[0],v[1]);
    }
    if(n==3)
    {
        return min(distanta(v[0],v[1]),min(distanta(v[0],v[2]), distanta(v[1],v[2])));
    }
    int m=n/2;
    float d=min(apropiere(v,m),apropiere(v+m,n-m));
    punct a[n];
    int k=-1;
    for(int i=0;i<n;i++)
        if(abs(v[i].x-v[m].x)<d)
            a[++k]=v[i];
    return min(d, det(a,k,d));
}

float rezolva(punct v[], int n)
{
    qsort(v,n,sizeof(punct),cmp1);
    return apropiere(v,n);
}

int main()
{
    punct v[100];
    int n;
    f>>n;
    for(int i=0;i<n;i++)
        f>>v[i].x>>v[i].y;
    g<<rezolva(v,n)<<endl;
    for(int i=0;i<2;i++)
        g<<sol[i].x<<" "<<sol[i].y<<endl;
    return 0;
}

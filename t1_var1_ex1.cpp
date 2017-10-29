#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;

ifstream f("date.in");
ofstream g("date.out");

struct interval
{
    int cap1;
    int cap2;
};

int cmp(const void *a, const void *b)
{
    interval p1=*(interval*)a;
    interval p2=*(interval*)b;
    return p1.cap2-p2.cap2;

}

int main()
{

    int n;
    interval a,v[100];
    f>>a.cap1>>a.cap2;
    f>>n;
    for(int i=1;i<=n;i++)
        f>>v[i].cap1>>v[i].cap2;
    qsort(v+1,n,sizeof(interval),cmp);
    interval s[100];
    int k=0;
    for(int i=1;i<=n;i++)
    {
        if(k==0)
            if(v[i].cap1<=a.cap1&&v[i].cap2>a.cap1)
                s[++k]=v[i];
        else{}
        else if(s[k].cap2<a.cap2)
                if(v[i].cap1<=a.cap1)
                    {
                        s[1]=v[i];
                        k=1;
                    }
                    else
                       if(v[i].cap1<=s[k].cap2&&v[i].cap2>=s[k].cap2&&v[i].cap1>=s[k].cap1&&v[i].cap1<=s[k-1].cap2&&k>=2)
                            s[k]=v[i];
                    else
                if(v[i].cap1<=s[k].cap2&&v[i].cap2>=s[k].cap2)
                    s[++k]=v[i];
    }
    if(k==0||s[k].cap2<a.cap2)
        g<<-1;
    else for(int i=1;i<=k;i++)
            g<<s[i].cap1<<" "<<s[i].cap2<<endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream f("date.in");
ofstream g("date.out");

struct subsir_mic {
  bool operator()(const stack<int> &sub1, const stack<int> &sub2) const {
    return sub1.top() < sub2.top();
  }
};


void rezolva(vector<int> a, int n) {
  typedef stack<int> sub;
  vector<sub> subsiruri;
   for (auto it =a.begin() ; it != a.end(); it++) {
    int& x = *it;
    sub nou;
    nou.push(x);
    vector<sub>::iterator i = lower_bound(subsiruri.begin(), subsiruri.end(), nou, subsir_mic());
    if (i != subsiruri.end())
      i->push(x);
    else
      subsiruri.push_back(nou);
  }

  while(!subsiruri.empty())
    {
    sub &aux = subsiruri.back();
    vector<int>v;
    while(!aux.empty())
    {
        v.push_back(aux.top());
        aux.pop();
    }
    for(int i=v.size()-1;i>=0;i--)
        g<<v[i]<<" ";
    g<<endl;
    subsiruri.pop_back();
  }
}
int main() {
  vector<int> a;
  int n,x;
  f>>n;
  for(int i=1;i<=n;i++)
  {
      f>>x;
      a.push_back(x);
  }
  rezolva(a,n);
  return 0;
}

#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream f("date.in");
ofstream g("date.out");
vector<int> a;

struct subsir_mic {
  bool operator()(const stack<int> &sub1, const stack<int> &sub2) const {
    return sub1.top() < sub2.top();
  }
};

struct subsir_mare {
  bool operator()(const stack<int> &sub1, const stack<int> &sub2) const {
    return sub1.top() > sub2.top();
  }
};

void rezolva(vector<int>a, int n) {
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
  make_heap(subsiruri.begin(), subsiruri.end(), subsir_mare());
  for (auto it =a.begin() ; it != a.end(); it++) {
    pop_heap(subsiruri.begin(), subsiruri.end(), subsir_mare());
    sub &mic = subsiruri.back();
    *it = mic.top();
    mic.pop();
    if (mic.empty())
      subsiruri.pop_back();
    else
      push_heap(subsiruri.begin(), subsiruri.end(), subsir_mare());
  }
  for(int i=0;i<a.size();i++)
    g<<a[i]<<" ";

}
int main() {
  int n,x;
  f>>n;
  for(int i=1;i<=n;i++)
  {
      f>>x;
      a.push_back(x);
  }
  rezolva(a, n);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline void pvec(vector<T> &vec) { for (T _vec : vec) { cout << _vec << " "; } cout << endl; } //

int main() {

  // DEBUG
  ifstream in("/home/konishi/workspace_atcoder/input.txt"); cin.rdbuf(in.rdbuf()); //

  int a,b,c,d;
  cin >> a >> b >> c >> d;

  cout << (a+b)*(c-d) << endl;
  cout << "Takahashi" << endl;
}

#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
inline bool chkchar(string &s, char c) { return s.find(c) != string::npos; }
template<class T> inline void pvec1(vector<T> &vec) { for (T _vec : vec) { cout << _vec << " "; } cout << endl; } //
template<class T> inline void pvec2(vector<vector<T>> &vec) { for (T v : vec) { for (T h : v) { cout << h << " "; } cout << endl; }} //

int main() {

  // DEBUG
  ifstream in("/home/konishi/workspace_atcoder/input.txt"); cin.rdbuf(in.rdbuf()); //

  string S, T;
  cin >> S;
  cin >> T;

  bool match = 1;

  if (T.size() < S.size())  match = 0;

  for (int i = 0; match && i < S.size(); i++) {
    if (S[i] != T[i]) match = 0;
  }

  cout << (match ? "Yes" : "No") << endl;
}

#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline void pvec(vector<T> &vec) { for (T _vec : vec) { cout << _vec << " "; } cout << endl; } //
inline bool chkchar(string &s, char c) { return s.find(c) != string::npos; }

int main() {

  // DEBUG
  ifstream in("/home/konishi/workspace_atcoder/input.txt"); cin.rdbuf(in.rdbuf()); //

  int A = 0, B = 10;
  int C = 0, D = 10;

  bool cd_done = 0;
  for (int i = 0; i < 10; i++) {
    string s;
    cin >> s;

    if (chkchar(s, '#')) {
      if (A == 0) A = i+1;

      // #が存在する行のときのみ走査する(走査後は固定する)
      for (int j = 0; !cd_done && j < 10; j++) {
        if (s[j] == '#') { if (C == 0) C = j+1; }
        if (s[j] == '.') { if (C != 0 && D == 10) D = j; }
      }
      cd_done = 1;
    }
    else {
      if (A != 0 && B == 10) B = i;
    }
  }
  cout << A << " " << B << endl;
  cout << C << " " << D << endl;
}

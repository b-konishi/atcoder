#include <bits/stdc++.h>
using namespace std;


template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
inline bool chkchar(string &s, char c) { return s.find(c) != string::npos; }
inline void YESNO(bool c) { cout << (c ? "YES" : "NO") << endl; }
inline void YesNo(bool c) { cout << (c ? "Yes" : "No") << endl; }
inline void yesno(bool c) { cout << (c ? "yes" : "no") << endl; }
template<class T> inline void pvec1(vector<T> &vec) { for (T _vec : vec) { cout << _vec << " "; } cout << endl; } //
template<class T> inline void pvec2(vector<vector<T>> &vec) { for (T v : vec) { for (T h : v) { cout << h << " "; } cout << endl; }} //


bool seven (int n) {
  int f = n%3;
  int f2 = n/3;

  int b = 111;
  if (f == 1) {
    b = 1;
  } else if (f == 2) {
    b = 11;
  }

  if (f2 % 2 ==0) {
    return (b%7) == 0;
  } else {
    return (111-b)%7 == 0;
  }
  return false;

}

bool cond (int n, int a) {
  switch (a) {
    case 1:
      return true;
    case 2:
      return false;
    case 3:
      return (n%3)==0;
    case 4:
      return (11%4)==0;
    case 5:
      return false;
    case 6:
      return false;
    case 7:
      return seven(n);
    case 8:
      return (111%8)==0;
    case 9:
      return (n%9)==0;
  }
  return false;
}

int main() {

  // DEBUG
  ifstream in("/home/konishi/workspace_atcoder/input.txt"); cin.rdbuf(in.rdbuf()); //

  int N, M;
  cin >> N >> M;


  bool finish = false;
  int a = -1;
  for (int i = N; !finish && i > 0; i--) {

    for (int x = 9; x > 0; x--) {

      int g;
      for (g = x; g >= 1; g--) {
        if (x % g != 0) continue;
        if (M % g != 0) continue;

        a = M / g;
        break;
      }
      if (i == 6 && x == 8) {
      cout << "x: " << x << endl;//
      cout << "g: " << g << endl;//
      cout << "a: " << a << endl;//
      cout << "i: " << i << endl;//
      cout << "i,a: " << (i%a) << endl;//
      }

      if (a != -1 && cond(i, a)) {

        for (int j = 0; j < i; j++) {
          cout << x;
        }
        finish = true;
        break;
      }
    }
    
  }
  if (!finish) cout << -1;

  cout << endl;
}

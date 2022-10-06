#include <bits/stdc++.h>
using namespace std;


template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

// Prime factorization (pair<value, ex>)
template<class T> inline vector<pair<T, T>> pf(T N) { vector<pair<T, T>> factors; for (T i = 2; i*i <= N; i++) { if (N % i == 0) { N /= i; T ex = 1; while (N % i == 0) { ex++; N /= i; } factors.push_back({i,ex}); } } if (N != 1) factors.push_back({N, 1}); return factors; }

// 文字列sに文字cが含まれるか
inline bool chkchar(string &s, char c) { return s.find(c) != string::npos; }

inline void YESNO(bool c) { cout << (c ? "YES" : "NO") << endl; }
inline void YesNo(bool c) { cout << (c ? "Yes" : "No") << endl; }
inline void yesno(bool c) { cout << (c ? "yes" : "no") << endl; }
template<class T> inline void pvec1(vector<T> &vec) { for (T _vec : vec) { cout << _vec << " "; } cout << endl; } //
template<class T> inline void pvec2(vector<vector<T>> &vec) { for (T v : vec) { for (T h : v) { cout << h << " "; } cout << endl; }} //

int main() {

  // DEBUG
  ifstream in("/home/konishi/workspace_atcoder/input.txt"); cin.rdbuf(in.rdbuf()); //

  int L, R;
  cin >> L >> R;

  string s = "atcoder";

  for (int i = L; i <= R; i++) {
    cout << s[i-1];
  }
  cout << endl;

}

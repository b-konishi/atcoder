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

#define MAXN 100000

int main() {

  // DEBUG
  ifstream in("/home/konishi/workspace_atcoder/input.txt"); cin.rdbuf(in.rdbuf()); //

  int N;
  cin >> N;

  // odd+odd or even+even のみevenになるため、分けて集めて最も大きい2つの数字の和を計算する
  vector<int> a_o;
  vector<int> a_e;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a % 2 == 1) {
      a_o.push_back(a);
    } else {
      a_e.push_back(a);
    }
  }
  sort(a_o.begin(), a_o.end());
  sort(a_e.begin(), a_e.end());

  int max_oo = -1, max_ee = -1;

  if (a_o.size() >= 2) {
    max_oo = a_o.at(a_o.size()-2) + a_o.at(a_o.size()-1);
  }

  if (a_e.size() >= 2) {
    max_ee = a_e.at(a_e.size()-2) + a_e.at(a_e.size()-1);
  }


  cout << max(max_oo, max_ee) << endl;
}

// 
// 7 4 2 1 3 6 10
//     8 5 9
// ピンの奥行き方向は関係ないため圧縮して、
// 2と8、3と9のそれぞれ少なくともどちらかが立っているかを調べる
// 左から立っているか確認していき、1 => 0 ... 0 => 1 のパターンがあればスプリット達成している
//
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

char atleast(char c1, char c2) {
  return (c1 == '1' || c2 == '1') ? '1' : '0';
}

int main() {

  // DEBUG
  ifstream in("/home/konishi/workspace_atcoder/input.txt"); cin.rdbuf(in.rdbuf()); //

  string s;
  cin >> s;

  if (s[0] == '1') { YesNo(false); return 0; }

  int hpins[7] = {s[6], s[4], atleast(s[1],s[7]), s[4], atleast(s[2],s[8]), s[5], s[9]};
  
  bool start = false, mid = false, end = false;
  for (int i = 0; i < 7; i++) {
    if (hpins[i] == '1') {
      start = true;
      if (mid)  end = true;
    }
    else {
      if (start)  mid = true;
    }
  }
  YesNo(end); 
}

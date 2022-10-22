#include <bits/stdc++.h>
using namespace std;


template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

// Prime factorization (pair<value, ex>)
template<typename T> inline vector<pair<T, T>> pf(T N) { vector<pair<T, T>> factors; for (T i = 2; i*i <= N; i++) { if (N % i == 0) { N /= i; T ex = 1; while (N % i == 0) { ex++; N /= i; } factors.push_back({i,ex}); } } if (N != 1) factors.push_back({N, 1}); return factors; }

// 文字列の個数検出
inline int cntchar(string s, char c) { int cnt = 0; for (int i = 0; i < s.length(); i++)  cnt += (s[i] == c); return cnt; }

// vectorの検索
template<typename T> inline int cntvec(vector<T>& v, T vi) { int cnt = 0; for (int i = 0; i < v.size(); i++)  cnt += (v[i] == vi); return cnt; }

inline void YESNO(bool c) { cout << (c ? "YES" : "NO") << endl; }
inline void YesNo(bool c) { cout << (c ? "Yes" : "No") << endl; }
inline void yesno(bool c) { cout << (c ? "yes" : "no") << endl; }

// for debug
template<typename T> inline void pvec1(vector<T>& vec) { cout << "["; for (auto v : vec) { cout << v << " "; } cout << "]" << endl; } //
template<typename T> inline void pvec2(vector<vector<T>>& vec) { cout << "=>" << endl; for (auto v : vec) { cout << "["; for (auto h : v) { cout << h << " "; } cout << "]" << endl; } cout << "<=" << endl; } //
template<typename T, typename U> inline void ppair(pair<T,U> p) { cout << "{" << p.first << "," << p.second << "}" << endl; } //
template<typename T, typename U, typename V> inline void ptuple3(tuple<T,U,V> t) { cout << "{" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << "}" << endl; } //

int main() {
  ifstream in("/home/konishi/workspace_atcoder/input.txt"); cin.rdbuf(in.rdbuf()); //

  int H, W;
  cin >> H >> W;

  std::vector<int> X(W, 0);

  for (int i = 0; i < H; ++i) {

    char c;
    for (int j = 0; j < W; ++j) {
      std::cin >> c;
      if (c == '#') {
        X.at(j) ++;
      }
      
    }
  }

  for (int i = 0; i < W; ++i) {
    std::cout << X.at(i) << std::endl;
  }


}

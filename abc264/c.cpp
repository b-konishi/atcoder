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
template<class T> inline void pvec1(vector<T> &vec) { for (T e : vec) { cout << e << " "; } cout << endl; } //
template<class T> inline void pvec2(vector<vector<T>> &vec) { for (vector<T> v : vec) { for (T h : v) { cout << h << " "; } cout << endl; }} //

int main() {

  // DEBUG
  ifstream in("/home/konishi/workspace_atcoder/input.txt"); cin.rdbuf(in.rdbuf()); //

  int H1, W1;
  cin >> H1 >> W1;
  vector<vector<int>> A(H1, vector<int>(W1,0));
  for (int i = 0; i < H1; i++)  for (int j = 0; j < W1; j++)  cin >> A.at(i).at(j);

  int H2, W2;
  cin >> H2 >> W2;
  vector<vector<int>> B(H2, vector<int>(W2,0));
  for (int i = 0; i < H2; i++)  for (int j = 0; j < W2; j++)  cin >> B.at(i).at(j);


  bool finish = false;
  for (int bit_h = 0; !finish && bit_h < (1<<H1); ++bit_h) {
    for (int bit_w = 0; !finish && bit_w < (1<<W1); ++bit_w) {
      
      // 削除しない行番号・列番号を記録
      vector<int> Dh, Dw;
      for (int i = 0; i < H1; i++)  if (bit_h & (1<<i)) Dh.push_back(i);
      for (int i = 0; i < W1; i++)  if (bit_w & (1<<i)) Dw.push_back(i);

      if (Dh.size() != H2 || Dw.size() != W2) continue;

      bool match = true;
      for (int i = 0; i < Dh.size(); i++) {
        for (int j = 0; j < Dw.size(); j++) {

          if (A.at(Dh.at(i)).at(Dw.at(j)) != B.at(i).at(j)) {
            match = false;
          }

        }
      }
      if (match)  finish = true;
      
    }

  }
  
  YesNo(finish);
}

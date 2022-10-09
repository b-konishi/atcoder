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

  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {

    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    pair<int,int> ones = {-1, -2};

    for (int i = 0; i < S.length(); i++) {
      if (S[i] == '1') {
        if (ones.first == -1) {
          ones = {i, i};
        }
        else {
          ones.second = i;
        }
      }
    }

    int num_ones = ones.second - ones.first + 1;

    if (num_ones >= 2) {
      bool finish = false;
      for (int i = ones.first+1; i < ones.second; i++) {
        if (S[i] == '0') {
          finish = true;
          break;
        }
        S[i] = '1';
      }
      if (finish) {
        YesNo(false);
        continue;
      }
    }

    if (num_ones == 0) {

      bool size_k = false;
      int st = -1;
      for (int i = 0; i < N; i++) {
        if (S[i] == '0') {
          size_k |= (i-st-1 == K);
          st = i;
        }
      }
      size_k |= (i-st-1 == K);

      YesNo(size_k);
      continue;
    }

    if (num_ones > K) {
      YesNo(false);
      continue;
    }
    else if (num_ones == K) {
      YesNo(true);
      continue;
    }


    // 左に何個広げられるか
    int able_left = 0;
    for (int i = ones.first-1; i >= 0; i--) {
      if (S[i] == '0')  break;
      if (S[i] == '?')  able_left ++;
    }

    // 右に何個広げられるか
    int able_right = 0;
    for (int i = ones.second+1; i < N; i++) {
      if (S[i] == '0')  break;
      if (S[i] == '?')  able_right ++;
    }

    cout << endl << able_left << ":" << able_right << endl;//
    YesNo(able_left + able_right + num_ones == K);
  }
}

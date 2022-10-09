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
template<class T> inline void pvec1(vector<T>& vec) { for (T _vec : vec) { cout << _vec << " "; } cout << endl; } //
template<class T> inline void pvec2(vector<vector<T>>& vec) { for (T v : vec) { for (T h : v) { cout << h << " "; } cout << endl; }} //
template<class T> inline void ppair(pair<T,T>& p) { cout << "{" << p.first << ", " << p.second << "}" << endl; } //





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

    // 文字列全体の'1'の数
    int M = 0;
    for (int i = 0; i < N; i++) M += (S[i] == '1');
    cout << "M: " << M << endl;//

    // '0','1'の数
    vector<pair<int,int>> counts(N-K+1, {0,0});

    int cnt = 0;
    for (int i = 0; i < K; i++) {
      counts.at(0).first += (S.at(i) == '0');
      counts.at(0).second += (S.at(i) == '1');
    }
    if (counts.at(0).first == 0 && counts.at(0).second == M) cnt++;
    ppair(counts.at(0));//

    for (int i = 1; i < N-(K-1); i++) {
      counts.at(i).first = counts.at(i-1).first - (S.at(i-1) == '0') + (S.at(i+K-1) == '0');
      counts.at(i).second = counts.at(i-1).second - (S.at(i-1) == '1') + (S.at(i+K-1) == '1');

      ppair(counts.at(i));//
      if (counts.at(i).first == 0 && counts.at(i).second == M) cnt++;
    }

    YesNo(cnt == 1);
  }
}

#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

#define INF 1e11+1
#define V 100*1e3

int knapsack(vector<vector<int64_t>> &dp, vector<pair<int64_t,int64_t>> &wv, int N, int W) {

  for (int j = 0; j <= V; j++) {
    // 0番目の価値v_0が現在の価値j以上ならば、w_0を代入
    if (j <= wv.at(0).second)  dp.at(0).at(j) = wv.at(0).first;
  }
  // 価値j=0であれば商品なしで満たす
  dp.at(0).at(0) = 0;

  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= V; j++) {

      // とりあえず(i-1)の状態(重さ)をコピー
      dp.at(i).at(j) = dp.at(i-1).at(j);

      /*
       * 自身の価値がj以上である場合、自身(のみ)を加えるか、加えない(前の状態を保持)かを選択できる
       * 自身の価値がj未満である場合、自身だけでは価値が足りない。
       * 「自身の重さ+足りない価値の分(i-1)から取得した重さ」と「前の状態を保持したときの重さ」を比較しより小さい方を採用する。
       */
      if (j <= wv.at(i).second) {
        chmin(dp.at(i).at(j), wv.at(i).first);
      } else {
        chmin(dp.at(i).at(j), wv.at(i).first + dp.at(i-1).at(j - wv.at(i).second));
      }
    }
  }

  // (N-1)の重さリストから制約Wを満たすぎりぎりの価値を取得
  for (int j = V; 1 <= j; j--) {
    if (dp.at(N-1).at(j) <= W)  return j;
  }
  return 0;
}

int main() {

  // cinでファイルから読込
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());

  int N, W;
  cin >> N >> W;

  vector<pair<int64_t,int64_t>> inputs(N);
  for (int i = 0; i < N; i++) { 
    cin >> inputs.at(i).first >> inputs.at(i).second;
  }

  // 縦: 商品インデックス, 横: 価値の大きさ(Max: Nmax*max(v_i)=1e5), 初期値(int64_t): INF=Nmax*max(w_i)+1=1e11+1
  vector<vector<int64_t>> dp(N, vector<int64_t>(100*1e3+1, INF));
  cout << knapsack(dp, inputs, N, W) << endl;
}


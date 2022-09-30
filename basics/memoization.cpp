#include <bits/stdc++.h>
using namespace std;

#define N 51

#define CARD_NUM 3
#define MAX_VALUE 10

#define SUSHI_NUM 5
#define MAX_KCAL 30 // times 10 [kcal]

vector<int> seq_sum(N, 0);
vector<int> seq_fib(N, 0);
vector<vector<int>> list_max(CARD_NUM, vector<int>(MAX_VALUE+1, 0));

vector<vector<int>> price_list_knapsack(SUSHI_NUM, vector<int>(MAX_KCAL+1, 0));


/* ナップサック問題 */
int knapsack (vector<int> &prices, vector<int> &cals) {
  
  for (int i = 0; i < SUSHI_NUM; i++) {
    for (int j = 0; j <= MAX_KCAL; j++) {

      if (i == 0) {
        if (cals[i] <= j) price_list_knapsack.at(0).at(j) = prices[i];
      }
      else {
        price_list_knapsack.at(i).at(j) = price_list_knapsack.at(i-1).at(j);

        if (cals[i] <= j
            && prices[i] + price_list_knapsack.at(i-1).at(j-cals[i]) > price_list_knapsack.at(i-1).at(j)
        ) {
          price_list_knapsack.at(i).at(j) = prices[i] + price_list_knapsack.at(i-1).at(j-cals[i]);
        }
      }

    }
  }

  return price_list_knapsack.at(SUSHI_NUM-1).at(MAX_KCAL);
}

/* 部分和問題 */
int find_max_dp (vector<int> &cards) {
  
  for (int i = 0; i < cards.size(); i++) {
    for (int j = 0; j <= MAX_VALUE; j++) {

      if (i == 0) {
        if (cards[i] <= j)  list_max.at(i).at(j) = cards[i];
      }
      else {
        // とりあえずi-1番目の状態をコピー
        list_max.at(i).at(j) = list_max.at(i-1).at(j);

        // i番目のカードを追加するなら書き換え
        if (cards[i] <= j && 
            cards[i] + list_max.at(i-1).at(j-cards[i]) > list_max.at(i-1).at(j)
        ) {
          list_max.at(i).at(j) = cards[i] + list_max.at(i-1).at(j-cards[i]);
        }
      }
    }
  }

  return list_max.at(CARD_NUM-1).at(MAX_VALUE);
}


/* フィボナッチ数列第n項 */
int fib (int n) {
  //printf("fib-(%d)\n", n);

  if (n == 0 || n == 1) {
    seq_fib[n] = 1;
    return 1;
  } 
  else {
    if (seq_fib[n] == 0)  seq_fib[n] = fib(n-2) + fib(n-1);
    return seq_fib[n];
  }
}

/* 1からnまでの総和 */
/* 実際はメモ化再帰の必要性はない */
int sum (int n) {
  // printf("sum(%d)\n", n);
  
  if (n == 1) {
    seq_sum[n] = 1;
    return 1;
  }
  else {
    if (seq_sum[n] == 0)  seq_sum[n] = sum(n-1) + n;
    return seq_sum[n];
  }
}


int main() {

  // ナップサック問題
  vector<int> prices = {120,150,140,110,100};
  vector<int> cals = {8,10,7,6,7};
  int m = knapsack(prices, cals);
  cout << "max-price: " << m << endl;
  for (int i = 0; i <= MAX_KCAL; i++) {
    printf("%4d ", i);
  }
  cout << endl;
  for (int i = 0; i < SUSHI_NUM; i++) {
    for (int j = 0; j <= MAX_KCAL; j++) {
      printf("%4d ", price_list_knapsack.at(i).at(j));
    }
    cout << endl;
  }


  // 部分和問題
  vector<int> cards = {6,2,3};
  cout << "max: " << find_max_dp(cards) << endl;

  for (int i = 0; i < CARD_NUM; i++) {
    for (int j = 0; j < MAX_VALUE+1; j++) {
      cout << list_max.at(i).at(j) << " ";
    }
    cout << endl;
  }

  // 1からnまでの総和
  cout << "sum(10): " << sum(10) << endl;

  // フィボナッチ数列
  cout << "fib(10): " << fib(10) << endl;



}

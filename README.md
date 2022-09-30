# atcoder

## Educational DP Contest

### A-Frog1
- 1次元DP

### B-Frog2
- 1次元DP

### C-Vacation
- 2次元DPを使用（縦:活動したときの瞬間幸福度 $A(i)$ (3種類:a/b/c), 横:日数 $N(j)$, 幸福度 $H(i,j)$ ）
- $H(i,j)$ <= $N(j-1)$ 日目の $A(i)$ 以外の活動の累積幸福度から最も高いものと、今日の活動 $A(i)$ の和
- 制約： $1\leq N \leq 10^5$, $1 \leq A_i \leq 10^4$
- 愚直計算量: $\mathcal{O}(2^N)$
- DP計算量: $\mathcal{O}(3N)=\mathcal{O}(N)$

### D-Knapsack1
- 2次元DPを使用(縦:商品インデックス $i < N$, 横:重さ $j < W$, 価値 $V(i,j)$ )
- 制約: $1 \leq N \leq 100$, $1 \leq v_i \leq 10^9$ (, $1 \leq W \leq 10^5$ ) であるため、 $1 \leq V(i,j) \leq 10^{11}$ となるため、 $-2 \times 10^9 \sim +2 \times 10^9$ 程度しか扱えない`int`(32bit)ではなく、`int64_t`を使用する
- 計算量: $\mathcal{O}(NW) \sim 10^7$

### E-Knapsnack2
- 問題はDと同様だが、制約条件のデータの範囲が異なる
- 制約: $1 \leq N \leq 100$, $1 \leq v_i \leq 10^3$, $1 \leq W \leq 10^9$
- 問題Dと同様に $N\times W$ のテーブルを組むと最悪 $10^11$ 程度のオーダーとなるため、間に合わない
- 横軸を価値 $V (1 \leq V \leq 10^5)$ に変更することでDPテーブルサイズは $100\times 10^5=10^7$ 程度に抑えられる
- 得られた重さが格納されたテーブルから、制限 $W$ 以内ギリギリの価値 $v$ を取得する
- 横軸のループの際には、以下を基準に条件分けする
  - 自身の価値がj以上である場合、自身(のみ)を加えるか、加えない(前の状態を保持)かを選択できる
  - 自身の価値がj未満である場合、自身だけでは価値が足りない。「自身の重さ+足りない価値の分(i-1)から取得した重さ」と「前の状態を保持したときの重さ」を比較しより小さい方を採用する。
- 計算量: $\mathcal{O}(NV+V)|_{V=Nv_i} = \mathcal{O}(N^2 v_i)$



## Tips

### 基本テンプレート

```cpp
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
```

### デバッグ用テンプレート
cinでファイルから読み込みことが可能。

```cpp
ifstream in("input.txt");
cin.rdbuf(in.rdbuf());
```



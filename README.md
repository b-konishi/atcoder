# atcoder

## Educational DP Contest
- https://atcoder.jp/contests/dp
- https://qiita.com/drken/items/dc53c683d6de8aeacf5a
- https://qiita.com/drken/items/03c7db44ccd27820ea0d

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

### F-LCS
- LCS(Longest Common Subsequence: 最長共通部分列)

## [ABC272](https://atcoder.jp/contests/abc272/editorial)

### D - Root M Leaper
- $(1,1)$ から移動できるマスへ有向辺を貼ることで重みなし(重み均一)有向グラフの最短経路問題になる
- キューとBFS(幅優先探索: breadth-first search)を用いて求められる
- グラフを作成する際に数学的考察を入れずに愚直に実装すると、ノード数 $N\times N (N\leq 400)$ であるため $\mathcal{O}(N^4) > 10^9$ となり計算量爆発を引き起こす
- 現在訪問中の座標を $(i,j)$ とし、接続先を $(k,l)$ とすると、距離は $(i-k)^2+(j-l)^2 = M$ となる
- $k$ と $l$ をどちらも動かすのは無駄であるため、 $k$ だけを動かしてみると、 $l = j\pm \sqrt{M-(k-i)^2}$ となり、ある $k$ に対して $l$ が2つ決まることがわかる
- まだ $(k,l_1), (k,l_2)$ がどこかに接続されていないか(親を持っていないか)を確認してから、未接続ならキューへ入れればよい
- これにより、計算量は $\mathcal{O}(N^3)$ となる (理想的には $\mathcal{O}(N^2\sqrt{M})$ で解けるらしい)

## ABC270

### A - 1-2-4 Test
- 試験の配点が(2^n)点になっているため、bit演算が可能である
- intでもbit演算は可能

### C - Simple path
- 木構造の表現方法

## ABC264

### B - Nice Grid
- チェビシェフ距離 $max(R_x, R_y)$
- 左上座標の場合は $max(|x-O_x|, |y-O_y|) \pmod 2$ で判定

### C - Matrix Reducing
- Bit全探索
- N個のアイテムの全組み合わせを探索するために、 $2^N$ `(1<<N)`回の繰り返しを行う。

```cpp
for (int bit = 0; bit < (1<<N); ++bit) { something; }
```
- 計算量 $\mathcal{O}(2^{(H_1+W_1)} \quad_{H_1} C_{H_1-H_2} \quad_{W_1} C_{W_1-W_2})$


## ARC149

### A - Repdigit Number
- https://atcoder.jp/contests/arc149/editorial/4869
- $1 \leq N \leq 10^5, X < 10^N \leq 10^{10^5} = 10^{100000}$ と非常に大きく全探索は当然不可能
- 一見、桁の大きい方から見ていき打ち切る方法が思いつくが、計算量削減のため、漸化式によって小さい方から進める必要がある。
- 漸化式は剰余情報のみ引き継げばよい
- 計算量 $\mathcal{O}(N) \leq 10^5$

モジュロ演算について
- https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#4-%E7%B4%AF%E4%B9%97-an
- $a(1,d) = d$, $a(2,d) = 10a(1,d)+d$
- $a(n,d) = 10a(n-1,d)+d$
- $a(N,d) < 10^n = 10^{10^5}$ となるため、剰余を保存する形式にしないとオーバーフローが発生する。
- 知りたい漸化式は $a(n,d)\bmod M \equiv (10 a_{n-1} + d)\bmod M$ となる。
- これは次の性質を利用している:
  - $a\bmod M = a - kM \equiv a\$ (何周回っても剰余は変わらない)
  - $a\bmod M\equiv b \Leftrightarrow a\equiv b$
  - $a(b\bmod M) \equiv (ab)\bmod M$
  - $a\bmod M + b \equiv (a+b)\bmod M$

## Tips

### 基本C++テンプレート
`template.cpp`を参照

### コンテスト環境構築用Linuxコマンド
コマンド定義は`atcoder.sh`ファイル参照。

```shell
cp atcoder.sh ~/command/atcoder
chmod 777 ~/command/atcoder
echo "export PATH=$HOME/command:$PATH" >> ~/.zshrc
echo "alias atcoder='source atcoder'" >> ~/.zshrc # shellで実行したcdをターミナルに反映させる
```

```
NAME
  atcoder - create an environment and execute automatically for AtCoder contests

SYNOPSIS
  atcoder -t [DIRECTORY]
  atcoder -e FILE
  atcoder -m DIRECTORY
  atcoder -g [STRING]
  atcoder -h

DESCRIPTION
  -t  create an environment by using tmux
  -e  execute a cpp-file automatically in case that the file is updated by constant monitoring    
  -m  make a directory and some cpp-files, that are required for the contest
  -g  execute git commands for commit and push
  -h  display this help and exit
```


### コード提出用Vimコマンド
デバッグ用のコードやコメント、空行を削除するために、`.vimrc`に記載する

```
nnoremap <C-y><C-y> :g/\v\/\/<BAR>^\s*$/d<ENTER>ggVGyu:nohlsearch<ENTER><C-o><C-o><C-o>
```






